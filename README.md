##About

[Spark Core](https://www.spark.io/) library for sending values to a [ThingSpeak](https://thingspeak.com/) channel. This library can be used in the [Spark IDE](https://www.spark.io/build).

## Getting Started

### 1. Include the library

Include the library from the [Spark IDE](https://www.spark.io/build) or download it to your local machine. Below is an example of including the library within the Spark IDE:

```cpp
#include "thingspeak/thingspeak.h"
```

### 2. Create thingspeak object

To use the library, an instance of the thingspeak class should be instaniated. The constructor requires a channel API key to be provided. This key can be obtained from the thingspeak website, more details available [here](https://thingspeak.com/docs/channels#api_keys). 

```cpp
    ThingSpeakLibrary::ThingSpeak thingspeak ("YOUR-CHANNEL-KEY");
```

### 3. Set values

There are two steps in sending values to thingspeak. Initially values must be given to some or all of the 9 fields supported by the thingspeak channel. The example belows sets a random integer to field 1:

```cpp
int rand = random(100);
thingspeak.recordValue(1, String(rand, DEC));
```

### 4. Send values

After setting, the values must be sent to thingspeak. The sendValues method constructs a GET query to the thingspeak API using any set values. Once the sendValues method has been called all the values are emptied. The example below sends any set values:

```cpp
bool valsSent = thingspeak.sendValues();
if(valsSent) {
    Serial.println("Value successfully sent to thingspeak");
} else {
    Serial.println("Sending to thingspeak failed");
}
```

Note: Values will be emptied after each send, if you want to maintain a value this should be set before each sendValues call.

## Examples

A full example can be found in firmware/examples which can be run within the [Spark IDE](https://www.spark.io/build).

## Contributing

Please feel free to suggest new features or contribute code