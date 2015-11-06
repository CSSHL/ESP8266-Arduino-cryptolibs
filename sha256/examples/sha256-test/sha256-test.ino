#include <sha256.h>

void setup() {
  BYTE hash[SHA256_BLOCK_SIZE];
  char texthash[2*SHA256_BLOCK_SIZE+1];

  Serial.begin(115200);

  Sha256* test=new Sha256();
  BYTE text[]="abc";
  test->update(text, strlen((const char*)text));
  test->final(hash);

  for(int i=0; i<SHA256_BLOCK_SIZE; ++i)
    sprintf(texthash+2*i, "%02X", hash[i]);
  Serial.println(texthash);
}

void loop() {
  delay(10);
}
