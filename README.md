# ESP32 WebSocket Server Sensor Dashboard

This project creates a WebSocket server on an ESP32 to display sensor readings from a BME280 sensor on a web dashboard.

## Table of Contents
- [Introduction](#introduction)
- [Hardware Required](#hardware-required)
- [Software Required](#software-required)
- [Installation](#installation)
- [Usage](#usage)
- [Web Interface](#web-interface)
- [License](#license)
- [Acknowledgments](#acknowledgments)
## Introduction
This project uses an ESP32 to read data from a BME280 sensor and serve these readings over a WebSocket connection to a web dashboard. The dashboard updates every 3 seconds with the latest sensor readings.

## Hardware Required
- ESP32 development board
- BME280 sensor
- Breadboard and jumper wires

## Software Required
- [PlatformIO](https://platformio.org/)
- Required PlatformIO libraries:
  - `Adafruit BME280 Library`
  - `ESPAsyncWebServer`
  - `AsyncTCP`
  - `ArduinoJson`

## Installation
1. Clone this repository or download the zip file and extract it.
2. Open the project in PlatformIO.
3. Install the required libraries mentioned above by adding them to your `platformio.ini` file:
    ```ini
    [env:esp32]
    platform = espressif32
    board = esp32dev
    framework = arduino
    lib_deps =
        adafruit/Adafruit BME280 Library @ ^2.1.2
        me-no-dev/ESP Async WebServer @ ^1.2.3
        me-no-dev/AsyncTCP @ ^1.1.1
        bblanchon/ArduinoJson @ ^6.18.3
    ```
4. Replace the placeholders for your Wi-Fi credentials in the code:
    ```cpp
    const char* ssid = "REPLACE_WITH_YOUR_SSID";
    const char* password = "REPLACE_WITH_YOUR_PASSWORD";
    ```
5. Upload the code to your ESP32 board using PlatformIO.

## Usage
1. Connect the BME280 sensor to the ESP32:
    - VIN to 3V3
    - GND to GND
    - SCL to GPIO 22
    - SDA to GPIO 21
2. Open the Serial Monitor to see the ESP32's IP address once it connects to your Wi-Fi.
3. Open a web browser and navigate to the ESP32's IP address to see the sensor readings dashboard.

## Web Interface
The web interface consists of three main files:
1. `index.html` - The main HTML file that sets up the structure of the dashboard.
2. `script.js` - The JavaScript file that handles the WebSocket connection and updates the dashboard with new sensor readings.
3. `style.css` - The CSS file that styles the dashboard.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is based on tutorials by Rui Santos & Sara Santos - [Random Nerd Tutorials](https://RandomNerdTutorials.com/)
