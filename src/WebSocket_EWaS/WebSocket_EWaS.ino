/*
  Earthquake Warning System using Wemos D1 R2 Wi-Fi Development Board Based on ESP8266 and ESP-12

  Created by: Sabiyo Riezky Pratama
  License: Public Domain (Creative Commons Zero v1.0 Universal)

  Based on the WebSocket server example by Shawn Hymel
  Original code: https://shawnhymel.com/1675/arduino-websocket-server-using-an-esp32/

  This code sets up an ESP8266-based system to monitor an MPU6050 accelerometer
  for shaking events. When shaking is detected, it triggers an alarm (buzzer and
  LED) and broadcasts an alert message via WebSocket. Periodically, it sends a 
  status update indicating no shaking detected.

  Hardware:
   - Wemos D1 R2 Wi-Fi Development Board based on ESP8266 and ESP-12
   - MPU6050 accelerometer and gyroscope sensor
   - Active 5V mini buzzer
   - Red LED

  Libraries used:
   - ESP8266WiFi.h (for Wi-Fi connectivity)
   - WebSocketsServer.h (for WebSocket communication)
   - Adafruit_MPU6050.h (for MPU6050 sensor)
   - Adafruit_Sensor.h (for sensor abstraction)
*/

#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Wi-Fi credentials
const char* ssid = "CHANGE TO YOUR WI-FI NETWORK NAME";
const char* password = "CHANGE TO YOUR WI-FI PASSWORD";

// Hostname for the ESP8266
String newHostname = "Earthquake Warning System (ESP8266)";

// Pin definitions for peripherals
int buzzerAlarm = 12;    // Pin for the alarm buzzer
int blinkingLED = 14;    // Pin for the blinking LED

// MPU6050 sensor object
Adafruit_MPU6050 mpu;

// WebSockets server object
WebSocketsServer webSocket = WebSocketsServer(80);

// Timing variables for periodic tasks
unsigned long previousMillis = 0;
const long interval = 5000;   // Interval for sending periodic updates (in milliseconds)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Set the hostname for the ESP8266
  WiFi.hostname(newHostname.c_str());

  // Initialize the MPU6050 sensor
  if (!mpu.begin()) {
    Serial.println("");
    Serial.println("MPU6050 initialization failed!");
    Serial.println("Try:");
    Serial.println("1. Press the RESET button");
    Serial.println("2. UNPLUG then PLUG BACK the cable from the USB port");
    while (1)
      ;   // Hang indefinitely if sensor initialization fails
  }

  // Set the accelerometer range to +/- 2G
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("Successfully connected to a Wi-Fi network!");
  Serial.println("---------------------------------------------");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Hostname: ");
  Serial.println(newHostname);
  Serial.println("---------------------------------------------");

  // Start the WebSocket server
  webSocket.begin();

  // Set pin modes for peripherals
  pinMode(buzzerAlarm, OUTPUT);
  pinMode(blinkingLED, OUTPUT);
}

void loop() {
  // Handle WebSocket events
  webSocket.loop();

  // Send periodic updates at specified interval
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    webSocket.broadcastTXT("(NORMAL: 0) No shaking detected..."); // Send WebSocket message
  }

  // Read accelerometer data
  sensors_event_t accel;
  mpu.getAccelerometerSensor()->getEvent(&accel);

  // Calculate magnitude of acceleration vector
  float magnitude = sqrt(accel.acceleration.x * accel.acceleration.x +
                         accel.acceleration.y * accel.acceleration.y +
                         accel.acceleration.z * accel.acceleration.z);

  // Check for shaking (magnitude exceeds threshold)
  if (magnitude > 1 * SENSORS_GRAVITY_EARTH) {
    // Alert via WebSocket and trigger alarm
    webSocket.broadcastTXT("(ALERT: 1) Shaking detected!"); // Send WebSocket message
    triggerAlarm(200);  // Trigger alarm for 200 iterations
  }
}

// Function to trigger the alarm (buzzer and LED)
void triggerAlarm(int blinkCount) {
  for (int i = 0; i < blinkCount; i++) {
    // Broadcast alert message via WebSocket
    webSocket.broadcastTXT("(ALERT: 1) Shaking detected!"); // Send WebSocket message

    // Activate buzzer and LED
    tone(buzzerAlarm, 2800);    // Activate buzzer at 2800 Hz
    digitalWrite(blinkingLED, HIGH);    // Turn on blinking LED
    delay(50);    // Delay for 50 milliseconds
    noTone(buzzerAlarm);    // Turn off the buzzer
    digitalWrite(blinkingLED, LOW);    // Turn off blinking LED
    delay(50);    // Delay for 50 milliseconds
  }
}