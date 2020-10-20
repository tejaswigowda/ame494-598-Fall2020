#define LILYGO_WATCH_2019_WITH_TOUCH
#include <LilyGoWatch.h>
TTGOClass *ttgo;

#include <SimpleDHT.h>


// for DHT11,
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 25
int pinDHT11 = 25;
SimpleDHT11 dht11(pinDHT11);



void setup() {
  Serial.begin(115200);
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    
    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->tft->setTextFont(4);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
 

  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print(String((float)temperature) + "* C, ");
  Serial.println(String((float)humidity) + "% H");

      ttgo->tft->drawString(String(temperature) + " *C",  5, 10);
      ttgo->tft->drawString(String(humidity) + " % H",  5, 40);


  // DHT11 sampling rate is 1HZ.
  delay(3500);
}
