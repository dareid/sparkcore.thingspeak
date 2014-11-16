#ifndef _THINGSPEAK_LIB
#define _THINGSPEAK_LIB

#include "application.h"

static const int NUMBER_OF_FIELDS = 9;
static const char THINGSPEAK_API [] = "api.thingspeak.com";
static const int RESPONSE_WAIT_TIME = 1500;


namespace ThingSpeakLibrary
{
    class ThingSpeak
    {
        private:
            TCPClient client;
            String key;
            String values [NUMBER_OF_FIELDS];
            String composeQuery();
        public:
            ThingSpeak(String apiKey);
            bool recordValue(int fieldId, String fieldValue);
            bool sendValues();

    };
}

#endif