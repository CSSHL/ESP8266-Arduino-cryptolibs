# ESP8266-Arduino-cryptolibs
Collection of strong crypto libs that can be included in Arduino-core for ESP8266

  - curve25519-donna : strong ECC key agreement function
  - esp8266-trng : simple wrapper to the HW TRNG
  - sha256 : SHA2-256 class

All these libs require that you already have:
  - installed [Arduino IDE](https://www.arduino.cc/en/Main/Software) for your platform; minimum release tested is 1.6.5, but should work with anything 1.5+
  - installed the [Arduino-core](https://github.com/esp8266/Arduino)
  - applied the [patch]https://github.com/esp8266/Arduino/commit/fe04165bbeafd0dcf5356172b2580655396279b0) if you get an error about iram0 filling up when you compile an example
  - copied the lib you need under the right folder (~/Arduino/libraries in Linux)
