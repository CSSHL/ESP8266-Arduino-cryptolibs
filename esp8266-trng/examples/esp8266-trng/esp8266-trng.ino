#include <esp8266-trng.h>

int counter=0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(!(counter&65535))	// slow down a bit...
    Serial.println(trng(), HEX);
  ++counter;
}

