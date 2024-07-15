![Title: Earthquake Warning System](https://github.com/sabiyorp/ESP8266-WebSocket-Earthquake-Alert/blob/main/img/Title.png)

# ESP8266 WebSocket Earthquake Warning System

**Welcome to the ESP8266 WebSocket Earthquake Warning System project!** This project uses an **Wemos D1 R2 Wi-Fi Based on ESP8266 & ESP-12 microcontroller** and an **MPU6050 sensor** to detect earthquakes and **send alert using WebSocket**.

## Features

- **Real-Time Detection**: Detect shaking with the MPU6050 sensor.
- **WebSocket Alerts**: Send instant alert via WebSocket.
- **Wi-Fi Connectivity**: Using the Wi-Fi local network to sends alerts.

## Components

- **Wemos D1 R2 Wi-Fi (ESP8266 & ESP-12)**
- **MPU6050 accelerometer and gyroscope**
- **LED light**
- **Buzzer**

## How It Works

1. **Monitor**: The MPU6050 sensor detects seismic activity.
2. **Process**: The Wemos board processes the data.
3. **Alert**: If an earthquake is detected, the ESP8266 sends alerts via WebSocket over Wi-Fi.

# Circuit Diagram

![Circuit Diagram](https://github.com/sabiyorp/ESP8266-WebSocket-Earthquake-Alert/blob/main/img/Circuit.jpg)

# Running the Arduino Sketch

1. Download the [sketch](https://github.com/sabiyorp/ESP8266-WebSocket-Earthquake-Alert/blob/main/src/WebSocket_EWaS/WebSocket_EWaS.ino).
2. Open the sketch on the [Arduino IDE](https://www.arduino.cc/en/software/).
3. Install the ESP8266 board manager [(tutorial)](https://github.com/esp8266/Arduino?tab=readme-ov-file#installing-with-boards-manager).
4. Select the ESP8266 board that you use, in this case it's `LOLIN(WEMOS) D1 R2 & mini`.
5. Install the required libraries using the Library Manager:
   - `WebSocketsServer.h`
   - `Adafruit_MPU6050.h`
   - `Adafruit_Sensor.h`
6. Update the Wi-Fi credentials in the sketch.
7. Upload the sketch to the ESP8266.
8. Open Serial Monitor to get the ESP8266's IP address.

---

Note: `ESP8266WiFi.h` is included with the ESP8266 board manager.

---

# Running the Python Script

1. Install [Python](https://www.python.org/downloads/).
2. Open Terminal and install the `websockets` library:
   ```bash
   pip install websockets
   ```
3. Download the [Python script](https://github.com/sabiyorp/ESP8266-WebSocket-Earthquake-Alert/blob/main/src/Python%20Script/get_ws_msg.py).
4. Open the script and replace `<ESP8266_IP_ADDRESS>` with your ESP8266's IP address.
5. In Terminal, type `cd` and type the script directory and it would look something like this:
   ```bash
   cd /Change/To/Your/Script/Directory
   ```
6. Run the script:
   ```bash
   python3 get_ws_msg.py
   ```
