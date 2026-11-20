// =====================================================================
// IoT 4WD Robot Car (NodeMCU ESP8266 + Blynk)
// ---------------------------------------------------------------------
// Board:        NodeMCU ESP8266
// Motor driver: L298N
// Control:      Blynk app over Wi-Fi (Serial monitor at 9600 baud)
//
// Pin map (NodeMCU -> L298N):
//   MOTORB_1  D4  -> IN3
//   MOTORB_2  D5  -> IN4
//   MOTORB_3  D1  -> IN1
//   MOTORB_4  D2  -> IN2
//
// Blynk virtual pins (buttons):
//   V1  forward   (MOTORB_1 / MOTORB_2)
//   V2  backward  (MOTORB_1 / MOTORB_2)
//   V3  forward   (MOTORB_3 / MOTORB_4)
//   V4  backward  (MOTORB_3 / MOTORB_4)
//
// Before uploading: set YOUR_AUTH_TOKEN, YOUR_WIFI_SSID and
// YOUR_WIFI_PASSWORD below.
//
// Author: Technolokar (Ajay Arjun Mannolkar)
// =====================================================================

//This code is written by Technolokar and it is used for making the IoT based Four wheel car using the Nodemcu.

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR_AUTH_TOKEN"; //This auth code is taking from the blynk cloud when we create the template of the project 
char ssid[] = "YOUR_WIFI_SSID";//The name of hotspot
char pass[] = "YOUR_WIFI_PASSWORD"; //Password of mobile hotspot

#define BLYNK_PRINT Serial

#define MOTORB_1 D4 //IN3
#define MOTORB_2 D5 //IN4
#define MOTORB_3 D1 //IN1
#define MOTORB_4 D2 //IN2

// SETUP
void setup()
{
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);
  pinMode(MOTORB_3, OUTPUT);
  pinMode(MOTORB_4, OUTPUT);

  // Start serial communication
  Serial.begin(9600);

  // Connect Blynk
  Blynk.begin(auth, ssid, pass);
}

// FORWARD 1
BLYNK_WRITE(V1) {
  int button = param.asInt(); // read button state from the Blynk app
  if (button == 1) {
    Serial.println("Moving forward");
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else {
    Serial.println("Stop");
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
// BACKWARD 1
BLYNK_WRITE(V2) {
  int button = param.asInt(); // read button state from the Blynk app
  if (button == 1) {
    Serial.println("Moving backward");
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }
  else {
    Serial.println("Stop");
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
// FORWARD 2
BLYNK_WRITE(V3) {
  int button = param.asInt(); // read button state from the Blynk app
  if (button == 1) {
    Serial.println("Moving forward");
    digitalWrite(MOTORB_3,LOW);
    digitalWrite(MOTORB_4,HIGH);
  }
  else {
    Serial.println("Stop");
    digitalWrite(MOTORB_3,LOW);
    digitalWrite(MOTORB_4,LOW);
  }
}
// BACKWARD 2
BLYNK_WRITE(V4) {
  int button = param.asInt(); // read button state from the Blynk app
  if (button == 1) {
    Serial.println("Moving backward");
    digitalWrite(MOTORB_3,HIGH);
    digitalWrite(MOTORB_4,LOW);
  }
  else {
    Serial.println("Stop");
    digitalWrite(MOTORB_3,LOW);
    digitalWrite(MOTORB_4,LOW);
  }
}

// MAIN LOOP
void loop()
{
  Blynk.run(); // keep the Blynk connection alive and handle button events
}
