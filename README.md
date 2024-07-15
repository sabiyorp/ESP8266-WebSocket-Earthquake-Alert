# ESP8266 WebSocket Earthquake Warning System

Welcome to the ESP8266 WebSocket Earthquake Warning System project! This project uses an ESP8266 microcontroller and an MPU6050 sensor to detect earthquakes in real-time and send alerts using WebSocket technology.

## Key Features

- **Real-Time Detection**: Detects seismic activity with the MPU6050 sensor.
- **WebSocket Alerts**: Sends quick alerts via WebSocket.
- **Wi-Fi Connectivity**: Uses ESP8266 for remote alerts.

## Components

- **Wemos D1 R2 Wi-Fi (ESP8266)**
- **MPU6050 accelerometer and gyroscope**
- **LED light**
- **Buzzer**

## How It Works

1. **Monitor**: The MPU6050 sensor detects seismic activity.
2. **Process**: The Wemos board processes the data.
3. **Alert**: If an earthquake is detected, the ESP8266 sends alerts via WebSocket over Wi-Fi.

## Circuit Diagram

![Circuit Diagram](https://github.com/sabiyorp/ESP8266-WebSocket-Earthquake-Alert/blob/main/img/Circuit.jpg)

## Running the Python Script

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

## Running the Arduino Sketch

1. Install the ESP8266 board manager [(tutorial)](https://github.com/esp8266/Arduino?tab=readme-ov-file#installing-with-boards-manager).
2. Select the ESP8266 board that you use, in this case it's `LOLIN(WEMOS) D1 R2 & mini`.
3. Install the required libraries using the Library Manager:
   - `WebSocketsServer.h`
   - `Adafruit_MPU6050.h`
   - `Adafruit_Sensor.h`
4. Update the Wi-Fi credentials in the sketch.
5. Upload the sketch to the ESP8266.

---

Note: `ESP8266WiFi.h` is included with the ESP8266 board manager.
