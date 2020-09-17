#include <Arduino.h>

const int ledPin = 22;

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 


char * HOSTNAME = "test12345";
char * WifiPASS = "";

#include <WiFi.h>
#include <WebServer.h>



WebServer server(80);


void setup() {
    Serial.begin(115200);


    ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);


    

    // Start Wifi AP
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(HOSTNAME, WifiPASS);


      
    // handle index -- HTTP Server

    
    server.on("/", []() {
      digitalWrite(21, 1);
      int v = server.arg("v").toInt();
      
      Serial.println(v);
      ledcWrite(ledChannel, map(v, 0, 100, 0, 255));

      server.send(200, "text/html", "<html><head><script>function foo(v){window.location.href=\"./?v=\" + v}</script></head><body><input type='range' max='100' min=\"0\" onchange='foo(this.value)' id='theText'></body><script>document.getElementById(\"theText\").value=parseInt(window.location.search.replace(\"?v=\",\"\"))</script><html>");
    });

    
    server.begin();
    
}

void loop() {
    server.handleClient();  
}
