Arduino-esp8266 porting of curve25519-donna.

curve25519 is an elliptic curve function for KEY AGREEMENT, like
Diffie-Hellman. No encryption. No signature. Just key setup!

Calling curve25519_donna() takes about 270ms, but yields 32 times so
that wifi and IP stacks can run.

* Copyright 2008, Google Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
*     * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
* copyright notice, this list of conditions and the following disclaimer
* in the documentation and/or other materials provided with the
* distribution.
*     * Neither the name of Google Inc. nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* curve25519-donna: Curve25519 elliptic curve, public key function
*
* http://code.google.com/p/curve25519-donna/
*
* Adam Langley <agl@imperialviolet.org>
*
* Derived from public domain C code by Daniel J. Bernstein <djb@cr.yp.to>
*
* More information about curve25519 can be found here
*   http://cr.yp.to/ecdh.html
*
* djb's sample implementation of curve25519 is written in a special assembly
* language called qhasm and uses the floating point registers.
*
* This is, almost, a clean room reimplementation from the curve25519 paper. It
* uses many of the tricks described therein. Only the crecip function is taken
* from the sample implementation.

Arduino-esp8266 port by Diego Zuccato <ndk.clanbo@gmail.com>
Main changes:
- renamed curve25519-donna.c to curve25519-donna.cpp
- moved datatypes definitions to curve25519-donna.h
- added yield() prototype in curve25519-donna.cpp
- added curve25519_donna_debug() that does a step at a time, to be able to
  obtain more finely-grained timing data
- ardulibrarization
