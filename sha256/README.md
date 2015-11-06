Hash SHA-256
Original source by Brad Conte (brad AT bradconte.com)
Ported to Arduino library and objectified by Diego Zuccato (ndk.clanbo@gmail.com)

Passed validations (from http://www.di-mgt.com.au/sha_testvectors.html ) :
  - "" => E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855
  - "abc" => BA7816BF8F01CFEA414140DE5DAE2223B00361A396177A9CB410FF61F20015AD
  - "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq" => 248D6A61D20638B8E5C026930C3E6039A33CE45964FF2167F6ECEDD419DB06C1
  - "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu" => CF5B16A778AF8380036CE59E7B0492370B249B11E8F07A51AFAC45037AFEE9D1
  - one million (1,000,000) repetitions of the character "a" (0x61) => CDC76E5C9914FB9281A1C7E284D73E67F1809A48A497200E046D39CCC7112CD0
  - the extremely-long message "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno" repeated 16,777,216 times: a bit string of length 2^33 bits => 50E72A0E26442FE2552DC3938AC58658228C0CBFB1D2CA872AE435266FCD055E

No failures in tested validation vectors.