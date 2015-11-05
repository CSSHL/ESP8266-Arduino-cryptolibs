/* From https://github.com/agl/curve25519-donna
*   USAGE:
*
*   The usage is exactly the same as djb's code (as described at
*   http://cr.yp.to/ecdh.html) expect that the function is called curve25519_donna.
*
*   In short:
*
*   To generate a private key just generate 32 random bytes.
*
*   To generate the public key, just do:
*
*     static const uint8_t basepoint[32] = {9};
*     curve25519_donna(mypublic, mysecret, basepoint);
*
*   To generate a shared secret do:
*
*     uint8_t shared[32];
*     curve25519_donna(shared, mysecret, theirpublic);
*
*   And hash the sender's public key, the recipient's public key, and shared_key
*   with a cryptographic hash function before using.
*/

// Requires fixes from https://github.com/esp8266/Arduino/commit/fe04165bbeafd0dcf5356172b2580655396279b0
#if !defined(CURVE25519_DONNA)
#define CURVE25519_DONNA

#include <stdint.h>

typedef uint8_t u8;
typedef int32_t s32;
typedef int64_t limb;

void curve25519_donna(u8 *mypublic, const u8 *secret, const u8 *basepoint);

#if DEBUG
u8 curve25519_donna_debug(u8 *mypublic, const u8 *secret, const u8 *basepoint);
#endif

#endif
