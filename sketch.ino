#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32-Servo";
const char* password = "12345678";

const int servoPin = 18;
const int blueLED = 26;
const int redLED = 27;

Servo myServo;
WebServer server(80);

void openServo() {
  myServo.write(90);
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, LOW);
  Serial.println("Servo OPEN");
}

void closeServo() {
  myServo.write(0);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, HIGH);
  Serial.println("Servo CLOSE");
}

void showPage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP32 Servo Control</title>
  <style>
    body {
      font-family: Arial;
      text-align: center;
      padding-top: 50px;
      background: #f4f7fb;
    }
    button {
      width: 160px;
      padding: 18px;
      margin: 12px;
      border: none;
      border-radius: 12px;
      color: white;
      font-size: 22px;
      cursor: pointer;
    }
    .open { background: #1976d2; }
    .close { background: #e53935; }
  </style>
</head>
<body>
  <h1>ESP32 Servo Control</h1>
  <a href="/open"><button class="open">Open</button></a>
  <a href="/close"><button class="close">Close</button></a>
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

  Serial.println();
  Serial.println("Access Point started");
  Serial.print("WiFi name: ");
  Serial.println(ssid);
  Serial.println("Password: 12345678");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", showPage);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);

  server.begin();
  Serial.println("Web server started");
  Serial.println("Wokwi test: type O for Open or C for Close");
}

void loop() {
  server.handleClient();

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
