// Be chatty over Serial
#define DEBUG 1

#include <curve25519-donna.h>

int counter=0;

void setup() {
  Serial.begin(115200); // Serial is on GPIO1(tx) and GPIO3(rx)
}

void doit(u8 *ek,const u8 *e,const u8 *k)
{
  int i;

  int start=millis();
  while(u8 s=curve25519_donna_debug(ek,e,k)) {
    int now=millis();
    Serial.print(s, DEC);
    Serial.print(" took ");
    Serial.println(now-start, DEC);
    start=now;
  }
  for (i = 0;i < 32;++i) Serial.print((unsigned int) e[i],HEX); Serial.print(" ");
  for (i = 0;i < 32;++i) Serial.print((unsigned int) k[i], HEX); Serial.print(" ");
  for (i = 0;i < 32;++i) Serial.print((unsigned int) ek[i], HEX); Serial.println("");
}

u8 e1k[32];
u8 e2k[32];
u8 e1e2k[32];
u8 e2e1k[32];
u8 e1[32] = {3};
u8 e2[32] = {5};
u8 k[32] = {9};

int cnt=0, err=0;

void loop() {
  int i;
  long start=millis();

  if(!err) {
    doit(e1k,e1,k);
    delay(0);
    doit(e2e1k,e2,e1k);
    delay(0);
    doit(e2k,e2,k);
    delay(0);
    doit(e1e2k,e1,e2k);
    delay(0);
    for (i = 0;i < 32;++i) if (e1e2k[i] != e2e1k[i]) {
      Serial.print("Fail at pass ");
      Serial.println(cnt, DEC);
      err=1;
    } else {
      ++cnt;
      for (i = 0;i < 32;++i) e1[i] ^= e2k[i];
      for (i = 0;i < 32;++i) e2[i] ^= e1k[i];
      for (i = 0;i < 32;++i) k[i] ^= e1e2k[i];
      long now=millis();
      Serial.print("Pass ");
      Serial.print(cnt, DEC);
      Serial.print(" COMPLETED in ");
      Serial.print(now-start, DEC);
      Serial.println("ms");
    }
  }
}
