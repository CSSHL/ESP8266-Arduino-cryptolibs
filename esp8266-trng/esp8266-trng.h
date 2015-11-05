#if !defined(ESP8266_TRNG)
#define ESP8266_TRNG

inline volatile int trng() {
    return *((volatile int*)0x3FF20E44);
}

#endif
