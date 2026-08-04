#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// WiFi information
const char* ssid = "ESP32-Servo";
const char* password = "12345678";

// Pins
const int servoPin = 18;
const int blueLED = 22;
const int redLED = 23;

Servo myServo;
WebServer server(80);

// Open
void openServo() {
  myServo.write(90);

  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, LOW);

  Serial.println("Servo OPEN");
}

// Close
void closeServo() {
  myServo.write(0);

  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, HIGH);

  Serial.println("Servo CLOSED");
}

// Web page
void showPage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <style>
    body {
      text-align: center;
      font-family: Arial;
      background: #f4f4f4;
      padding-top: 70px;
    }

    button {
      width: 180px;
      padding: 18px;
      margin: 12px;
      border: none;
      border-radius: 12px;
      color: white;
      font-size: 22px;
    }

    .open {
      background: #2196F3;
    }

    .close {
      background: #E53935;
    }
  </style>
</head>

<body>
  <h1>ESP32 Servo Control</h1>

  <a href="/open">
    <button class="open">Open</button>
  </a>

  <a href="/close">
    <button class="close">Close</button>
  </a>
</body>
</html>
)rawliteral";

  server.send(200, "text/html", page);
}

void handleOpen() {
  openServo();
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleClose() {
  closeServo();
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);

  closeServo();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  server.on("/", showPage);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);
  server.begin();

  Serial.println("WiFi started");
  Serial.println("Open: http://192.168.4.1");
}

void loop() {
  server.handleClient();

  // Control from Serial Monitor
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'O' || command == 'o') {
      openServo();
    }

    if (command == 'C' || command == 'c') {
      closeServo();
    }
  }
}
