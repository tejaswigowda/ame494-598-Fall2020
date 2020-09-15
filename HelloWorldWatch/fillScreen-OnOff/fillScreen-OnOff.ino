#define LILYGO_WATCH_2019_WITH_TOUCH
#include <LilyGoWatch.h>

TTGOClass *ttgo;

bool screenOn = true;

void pressed()
{
  screenOn = !screenOn;
}
void released()
{
}

void setup()
{
    Serial.begin(115200);
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();

    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->tft->setTextFont(4);
    ttgo->tft->drawString("User Button released",  5, 100, 4);

    ttgo->button->setPressedHandler(pressed);
    ttgo->button->setReleasedHandler(released);

}

void loop()
{
    ttgo->button->loop();


    Serial.println("R");
    if(screenOn){
      ttgo->tft->fillScreen(TFT_RED);
      delay(1000);
      Serial.println("G");
      ttgo->tft->fillScreen(TFT_GREEN);
      delay(1000);
      Serial.println("B");
      ttgo->tft->fillScreen(TFT_BLUE);
      delay(1000);
    }
    else{
            ttgo->tft->fillScreen(TFT_BLACK);
    }
    
}
