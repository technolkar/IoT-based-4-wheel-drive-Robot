//This code is written by Technolokar and it is used for making the IoT based Four wheel car using the Nodemcu.

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "lnblxbbMVCTcjYAmbjtawTyt1_-iO0KN"; //This auth code is taking from the blynk cloud when we create the template of the project 
char ssid[] = "project2G";//The name of hotspot
char pass[] = "techo123"; //Password of mobile hotspot

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
