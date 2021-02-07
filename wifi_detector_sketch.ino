#define ONBOARD_LED  2
#include "WiFi.h"

void setup() {
  Serial.begin(9600);
  delay(3000);
  pinMode(ONBOARD_LED, OUTPUT);
  const char* ssid = "Yaakov iPhone";
  const char* password =  "gggggggg";
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi successfully");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    delay(1000);
    Serial.println("Turning on led");
    digitalWrite(ONBOARD_LED, HIGH);
    delay(2000);
    Serial.println("Turning off led");
    digitalWrite(ONBOARD_LED, LOW);
  } else {
    Serial.println("wifi not connected, not blinking");
  }

}
