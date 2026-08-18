# ESP32CherryIoT

<p align="right"><strong><big>⇄ <a href="README.md">日本語</a></big></strong></p>

CrowTail+ESP32 dongle

<p style="display: inline">
  <img src="https://img.shields.io/badge/-Arduino-00979D.svg?logo=arduino&style=plastic">
  <img src="https://img.shields.io/badge/-Cplusplus-00599C.svg?logo=cplusplus&style=plastic">
  <img src="https://img.shields.io/badge/-Github-181717.svg?logo=github&style=plastic">
  <img src="https://img.shields.io/badge/-WiFi-666666.svg?logo=RSS&style=plastic">
  <img src="https://img.shields.io/badge/-Bluetooth-666666.svg?logo=Bluetooth&style=plastic">
</p>

## About CherryIoT

CherryIoT is an ESP32-based device for IoT development and learning.  
By connecting sensors and various modules, you can easily experiment with IoT using the Arduino IDE.

CherryIoT can be used as teaching and hands-on training material for IoT education in schools and training programs, as well as for agricultural IoT using sensors and proof-of-concept (PoC) projects in manufacturing.

This GitHub repository provides the basic settings and sample code needed to use CherryIoT.  
For detailed instructions, examples, and future use cases, please visit the official CherryIoT website.

▶ [CherryIoT Official Website](https://iot.cherrychain.cc/)

## Settings

### Install the driver

Type the following command in PowerShell.

```
Invoke-WebRequest 'https://dl.espressif.com/dl/idf-env/idf-env.exe' -OutFile .\idf-env.exe; .\idf-env.exe driver install --espressif
```

### Install Arduino IDE

Install Arduino IDE.

### Add the ESP32 Boards Manager URL

Add the following URL to your Arduino IDE preferences.

```
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

### Install ESP32

Install "ESP32 by Espressif Systems" from Boards Manager.

## Basic Usage

### Insert the ESP32 CherryIoT into your PC

Insert the ESP32 CherryIoT into your PC.

### Arduino IDE Tools

In Arduino IDE, configure the following settings under Tools.

- Board: ESP32C3 Dev Module
- Port: COMXX (By your PC)
- USB CDC On Boot: "Enabled"
- Upload Speed: 256000

### Upload the program

Select the program you want to write and press the Upload button.

![2024-10-19_08h26_05](https://github.com/user-attachments/assets/8b5b5ec8-ccfd-42dc-8a83-d64339d6de8b)

## BasicKit

![BasicKit](https://github.com/user-attachments/assets/10f4b977-4d59-4b13-a50c-cb77bddf4d6f)

▶ [Purchase BasicKit here](https://btoshop.jp/products/jm00007)

### Examples using BasicKit

- The LED turns on when it gets dark
- The propeller spins when the switch is pressed
- A sound plays when touched
- The servo motor moves when you approach
- Temperature and humidity are measured and displayed on the OLED
- Counts passing objects and vibrates after 5 objects pass

and more
