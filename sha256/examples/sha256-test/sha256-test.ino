#include <sha256.h>

void setup() {
  BYTE hash[SHA256_BLOCK_SIZE];
  char texthash[2*SHA256_BLOCK_SIZE+1];

  Serial.begin(115200);

  Sha256* sha256Instance=new Sha256();
  BYTE text[]="abc";
  sha256Instance->update(text, strlen((const char*)text));
  sha256Instance->final(hash);

  for(int i=0; i<SHA256_BLOCK_SIZE; ++i)
    sprintf(texthash+2*i, "%02X", hash[i]);
  Serial.println(texthash);
  
  delete sha256Instance;
}

void loop() {
  delay(10);
}
