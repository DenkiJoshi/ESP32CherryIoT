# ESP32CherryIoT

CrowTail+ESP32 dongle

<p style="display: inline">
  <img src="https://img.shields.io/badge/-Arduino-00979D.svg?logo=arduino&style=plastic">
  <img src="https://img.shields.io/badge/-Cplusplus-00599C.svg?logo=cplusplus&style=plastic">
  <img src="https://img.shields.io/badge/-Github-181717.svg?logo=github&style=plastic">
  <img src="https://img.shields.io/badge/-WiFi-666666.svg?logo=RSS&style=plastic">
  <img src="https://img.shields.io/badge/-Bluetooth-666666.svg?logo=Bluetooth&style=plastic">
</p>

## Settings

- Install the driver
Type this command in powershell

```
Invoke-WebRequest 'https://dl.espressif.com/dl/idf-env/idf-env.exe' -OutFile .\idf-env.exe; .\idf-env.exe driver install --espressif
```

- Install Arduino IDE

- Add the following URL to your preferences

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

- Install ESP32 by espressif from Boards Manager


## Basic Usage

- Insert the ESP32 CherryIoT into your PC.

- Tool
    Board:ESP32C3
    Port:comXX (By your PC)
    Upload Speed:256000

- Select the program you want to write and press the Write button.