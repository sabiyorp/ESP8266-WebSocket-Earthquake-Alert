'''
Created by: Sabiyo Riezky Pratama
License: Public Domain (Creative Commons Zero v1.0 Universal)

Based on the WebSocket server example by Shawn Hymel
Original code: https://shawnhymel.com/1675/arduino-websocket-server-using-an-esp32/
'''

import asyncio
import websockets

async def receive_message():
    uri = "<ESP8266_IP_ADDRESS>"  # Replace <ESP8266_IP_ADDRESS> with the actual IP address of your ESP8266
    while True:
        try:
            async with websockets.connect(uri) as websocket:
                while True:
                    try:
                        message = await asyncio.wait_for(websocket.recv(), timeout=3.0)
                        print(f"Received message: {message}")
                    except asyncio.TimeoutError:
                        print("Reconnecting...")
                        break
        except (websockets.exceptions.ConnectionClosedError, websockets.exceptions.InvalidURI) as e:
            print(f"Connection error: {e}. Reconnecting...")
            await asyncio.sleep(5)  # Wait before retrying the connection
        except Exception as e:
            print(f"An unexpected error occurred: {e}. Reconnecting...")
            await asyncio.sleep(5)  # Wait before retrying the connection

if __name__ == "__main__":
    asyncio.run(receive_message())
