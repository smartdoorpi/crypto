1. Compile using g++ DSA.cpp -o DSA
2. Run using ./DSA


Example:


Enter the Message to be sent :  12345678

12345678
1394003017860

The hash is :  0x 144910e0084
Enter Passkey for encryption :  23456
811360898154572601

The Encrypted hash is :  0x b42887027252b39

Simulating message transmission
.  .  .  .  .  .  .  .  .  .
To edit message enter 1
To continue enter any other key  5678

Received Message   :   12345678
Received encrypted hash  :   0x b42887027252b39
Hash of received message :   0x 144910e0084

We decrypt received encrypted hash
Enter passkey to decrypt encrypted hash :  123

Decrypted hash is :  0x 144910e0084

Since both hash of received message, and decrypted received encrypted hash
are the same, Digital Signature is verified


