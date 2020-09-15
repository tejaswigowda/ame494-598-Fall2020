#include <TTGO.h>
TTGOClass *ttgo;

String inData;

void setup() {
  // initialize serial:
   Serial.begin(115200);
   ttgo = TTGOClass::getWatch();
   ttgo->begin();
   ttgo->openBL();

   ttgo->eTFT->fillScreen(TFT_BLACK);
   ttgo->eTFT->setTextColor(TFT_WHITE, TFT_BLACK);
   ttgo->eTFT->setTextFont(4);
}

void loop() {
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; 

        // Process message when new line character is recieved
        if (recieved == '\n')
        {
            Serial.print("Message Received: ");
            Serial.print(inData);

            ttgo->eTFT->fillScreen(TFT_BLACK);
            ttgo->eTFT->drawString(inData,  5, 10);
            
            inData = ""; // Clear recieved buffer
        }
    }
}
