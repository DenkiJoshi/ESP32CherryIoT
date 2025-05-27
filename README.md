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
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

- Install ESP32 by espressif from Boards Manager


## Basic Usage

- Insert the ESP32 CherryIoT into your PC.

- [Arduino IDE] Tools
  - Board:ESP32C3 Dev Module
  - Port:COMXX (By your PC)
  - USB CDC On Boot:"Enabled"
  - Upload Speed:256000

- Select the program you want to write and press the Upload button.

![2024-10-19_08h26_05](https://github.com/user-attachments/assets/8b5b5ec8-ccfd-42dc-8a83-d64339d6de8b)