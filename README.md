# ESP32-WiFi-Servo-Control
# 🌐 ESP32 WiFi Servo Control

## 📌 Project Overview

This project demonstrates how to control an SG90 Servo Motor using an ESP32 board through a simple web interface.

The ESP32 creates its own WiFi Access Point. After connecting to the ESP32 network, the user can open a control page containing **Open** and **Close** buttons.

The project was first tested virtually using the **Wokwi simulator** and then implemented using real ESP32 hardware.

## ✨ Features

* 📶 Creates a local WiFi Access Point.
* 🌐 Provides a simple web control page.
* 🔓 Open button moves the Servo Motor to 90°.
* 🔒 Close button returns the Servo Motor to 0°.
* 🔵 Blue LED indicates the Open state.
* 🔴 Red LED indicates the Close state in the simulation.
* 📱 Can be controlled using a phone or computer.
* 💻 Tested using Wokwi and real hardware.

## 🧰 Components

### 💻 Wokwi Simulation

* ESP32 Development Board
* SG90 Servo Motor
* Blue LED
* Red LED
* Two 220Ω resistors
* Jumper wires

### 🔌 Real Hardware

* ESP32 Board
* SG90 Servo Motor
* Male-to-Male jumper wires
* USB data cable
* Built-in blue LED on the ESP32

## 🔗 Wokwi Wiring

| Component    | ESP32 Connection                |
| ------------ | ------------------------------- |
| Servo signal | GPIO 18                         |
| Servo VCC    | 5V                              |
| Servo GND    | GND                             |
| Blue LED     | GPIO 2 through a 220Ω resistor  |
| Red LED      | GPIO 27 through a 220Ω resistor |

## 🔧 Real Hardware Wiring

| Servo Wire  | ESP32 Connection | Function             |
| ----------- | ---------------- | -------------------- |
| Red wire    | VCC              | Servo power          |
| Brown wire  | GND              | Ground               |
| Orange wire | IO18             | Servo control signal |

The built-in blue LED uses `GPIO 2`, so it does not require any external wiring.

> ⚠️ Disconnect the USB cable before connecting or changing any wires.

## ⚙️ How It Works

1. The ESP32 creates a local WiFi network.
2. The user connects a phone or computer to the ESP32 network.
3. The user opens `http://192.168.4.1` in a browser.
4. The ESP32 displays a web page with Open and Close buttons.
5. Pressing **Open** moves the Servo Motor to 90° and turns on the blue LED.
6. Pressing **Close** returns the Servo Motor to 0° and turns off the blue LED.
7. In the Wokwi simulation, the red LED turns on during the Close state.

## 🌐 Wokwi Simulation

The circuit and code were first tested virtually using the Wokwi simulator.

https://wokwi.com/projects/471183592177360897

### 🎥 Wokwi Simulation Run

Here we show the project running in the Wokwi simulator.

https://github.com/user-attachments/assets/0dab219f-925f-41a5-994e-55c59191abb0

In the simulation, the Servo Motor can also be controlled using the Serial Monitor:

* Enter `O` to Open.
* Enter `C` to Close.

## 🛠️ Real Hardware Implementation

After successfully testing the circuit in Wokwi, the project was implemented using a real ESP32 board and an SG90 Servo Motor.

The built-in blue LED on the ESP32 was used as the Open status indicator.

### 🎥 Real Hardware Run

Here we show the project running using the real ESP32 board and SG90 Servo Motor.

https://github.com/user-attachments/assets/c3a07d44-d359-4a9b-bf23-f335bde9ccf2

## 💻 Software and Libraries

The project was programmed using the Arduino IDE.

### Required Libraries

* `WiFi.h`
* `WebServer.h`
* `ESP32Servo.h`

The `WiFi` and `WebServer` libraries are included with the ESP32 board package.

The `ESP32Servo` library can be installed from:

`Arduino IDE → Sketch → Include Library → Manage Libraries`

## ⬆️ Uploading the Code

1. Disconnect the Servo Motor from the ESP32.
2. Connect the ESP32 to the computer using a USB data cable.
3. Open the project code in the Arduino IDE.
4. Select `ESP32 Dev Module` from the Boards menu.
5. Select the correct COM port.
6. Set the Upload Speed to `115200`.
7. Click the Upload button.
8. Wait until `Done uploading` appears.
9. Disconnect the USB cable.
10. Connect the Servo Motor to `VCC`, `GND`, and `IO18`.
11. Reconnect the USB cable.

## ▶️ Running the Real Project

1. Power the ESP32 using the USB cable.
2. Open the WiFi settings on the phone or computer.
3. Connect to the WiFi network created by the ESP32.
4. Open a web browser.
5. Enter `http://192.168.4.1`.
6. Press Open or Close to control the Servo Motor.

## 📁 Repository Files

* `code.ino` — ESP32 source code.
* `diagram.json` — Wokwi circuit design.
* `libraries.txt` — Required Wokwi libraries.
* `wokwi-project.txt` — Wokwi project information.
* `README.md` — Project documentation.

## ✅ Project Result

The project was successfully tested in the Wokwi simulator and implemented using real ESP32 hardware.

The ESP32 successfully created a local WiFi network, displayed the web control page, and controlled the Servo Motor using the Open and Close buttons.

---

### 👩‍💻 Developed by Amal Yasser
