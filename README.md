# ESP32CherryIoT

<p align="right"><strong><big>⇄ <a href="README_EN.md">English</a></big></strong></p>

CrowTail+ESP32 dongle

<p style="display: inline">
  <img src="https://img.shields.io/badge/-Arduino-00979D.svg?logo=arduino&style=plastic">
  <img src="https://img.shields.io/badge/-Cplusplus-00599C.svg?logo=cplusplus&style=plastic">
  <img src="https://img.shields.io/badge/-Github-181717.svg?logo=github&style=plastic">
  <img src="https://img.shields.io/badge/-WiFi-666666.svg?logo=RSS&style=plastic">
  <img src="https://img.shields.io/badge/-Bluetooth-666666.svg?logo=Bluetooth&style=plastic">
</p>

## CherryIoTについて

CherryIoTは、ESP32をベースにしたIoT開発・学習用デバイスです。  
センサーや各種モジュールを接続し、Arduino IDEを使って手軽にIoTの仕組みを試すことができます。

学校や研修でのIoT教育・実習教材としての活用をはじめ、センサーを使った農業IoT、製造業でのPoC（概念実証）など、幅広い用途に活用できます。

このGitHubでは、CherryIoTを動かすための基本設定やサンプルコードを公開しています。  
使い方、サンプル、活用例などの詳しい情報はCherryIoT公式Webサイトをご覧ください。

▶ [CherryIoT 公式Webサイト](https://iot.cherrychain.cc/)

## 設定

### ドライバをインストールする

PowerShellで以下のコマンドを実行します。

```
Invoke-WebRequest 'https://dl.espressif.com/dl/idf-env/idf-env.exe' -OutFile .\idf-env.exe; .\idf-env.exe driver install --espressif
```

### Arduino IDEをインストールする

Arduino IDEをインストールします。

### ESP32ボードマネージャーURLを追加する

Arduino IDEの環境設定に、以下のURLを追加します。

```
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

### ESP32ボードをインストールする

ボードマネージャーから「ESP32 by Espressif Systems」をインストールします。

## 基本的な使い方

### ESP32 CherryIoTをPCに接続する

ESP32 CherryIoTをPCに接続します。

### Arduino IDEのツール設定

Arduino IDEの「ツール」で、以下のように設定します。

- Board: ESP32C3 Dev Module
- Port: COMXX（使用するPCによって異なります）
- USB CDC On Boot: "Enabled"
- Upload Speed: 256000

### プログラムを書き込む

書き込みたいプログラムを選択し、Uploadボタンを押します。

![2024-10-19_08h26_05](https://github.com/user-attachments/assets/8b5b5ec8-ccfd-42dc-8a83-d64339d6de8b)

## BasicKit

![BasicKit](https://github.com/user-attachments/assets/10f4b977-4d59-4b13-a50c-cb77bddf4d6f)

### BasicKitを使った作例

- 暗くなるとLEDが点灯する
- スイッチを押すとプロペラが回る
- タッチすると音が鳴る
- 近づくとサーボモーターが動く
- 温度・湿度を測定してOLEDに表示する
- 物の通過を数え、5個通過すると振動で知らせる

など

▶ [BasicKitの購入はこちら](https://btoshop.jp/products/jm00007)