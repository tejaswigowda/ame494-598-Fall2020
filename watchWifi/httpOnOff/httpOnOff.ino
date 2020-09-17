#include <Arduino.h>

char * HOSTNAME = "testing";
char * WifiPASS = "12345678";

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);



void setup() {
    Serial.begin(115200);
    pinMode(21, OUTPUT);

    // Start Wifi AP
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(HOSTNAME, WifiPASS);
    // handle index -- HTTP Server
    
    server.on("/on", []() {
      Serial.println(1);
      digitalWrite(21, HIGH);
      server.send(200, "");
    });

    server.on("/off", []() {
      Serial.println(0);
      digitalWrite(21, LOW);
      server.send(200, "");
    });
 
    server.begin();
    
}

void loop() {
    server.handleClient();
}
