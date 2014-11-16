#include "thingspeak.h"

ThingSpeakLibrary::ThingSpeak::ThingSpeak(String apiKey) 
{
    key = apiKey;
}

bool ThingSpeakLibrary::ThingSpeak::recordValue(int fieldId, String fieldValue)
{
    if(fieldId < 1 || fieldId > NUMBER_OF_FIELDS) {
        return false;
    }
    values[fieldId-1] = fieldValue;
    return true;
}

String ThingSpeakLibrary::ThingSpeak::composeQuery()
{
    String result = String ("/update?key=" + key);
    for(int ct = 0; ct < NUMBER_OF_FIELDS; ct++) 
    {
        if(values[ct] != NULL) 
        {
            String fieldParameter = String("&field" + String((ct+1), DEC) + "=" + values[ct]);
            result.concat(fieldParameter);
            values[ct] = NULL;
        }
    }
    return result;
}

bool ThingSpeakLibrary::ThingSpeak::sendValues() 
{
    if (client.connect(THINGSPEAK_API, 80))
    {
        bool ret = false;
        client.println(String("GET " + this->composeQuery() + " HTTP/1.0"));
        client.println(String("Host: " + String(THINGSPEAK_API)));
        client.println("Content-Length: 0");
        client.println();
        
        int i = 0;
        uint32_t lastRead = millis();
        while ((millis() - lastRead) < RESPONSE_WAIT_TIME) {
            while (client.available() > 0) {
                ret = true;
                client.flush();
                lastRead = millis();
            }
        }
        client.flush();
        client.stop();
        
        return ret;
    }
    else
    {
        return false;
    }
}