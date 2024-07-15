# Created by: Sabiyo Riezky Pratama
# License: Public Domain (Creative Commons Zero v1.0 Universal)

import asyncio
import websockets

async def receive_message():
    uri = "ws://<ESP8266_IP_ADDRESS>:80"  # Replace <ESP8266_IP_ADDRESS> with the actual IP address of your ESP8266
    async with websockets.connect(uri) as websocket:
        while True:
            message = await websocket.recv()
            print(f"Received message: {message}")

if __name__ == "__main__":
    asyncio.run(receive_message())
