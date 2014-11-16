// This #include statement was automatically added by the Spark IDE.
#include "thingspeak/thingspeak.h"

ThingSpeakLibrary::ThingSpeak thingspeak ("YOUR-CHANNEL-KEY");

void setup() {
    Serial.begin(9600);
}

void loop() {
    
    Serial.println("Loop start");
    
    int rand = random(100);
    bool valSet = thingspeak.recordValue(1, String(rand, DEC));
    if(valSet) {
        Serial.println("Value set to field 1 : " + String(rand, DEC));
    } else {
        Serial.println("Value not set successfully");
    }
    
    bool valsSent = thingspeak.sendValues();
    if(valsSent) {
        Serial.println("Value successfully sent to thingspeak");
    } else {
        Serial.println("Sending to thingspeak failed");
    }
    
    delay(16000);
    
}