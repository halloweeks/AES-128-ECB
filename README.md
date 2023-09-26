# Custom AES-128 Encryption Implementation with 12 Rounds

## Overview

This GitHub repository contains a custom implementation of the Advanced Encryption Standard (AES) with a focus on AES-128 encryption. It features an enhanced version with 12 rounds for improved security and cryptographic strength.

## Features

- **Extended Rounds:** This custom AES-128 variant includes 12 rounds, offering enhanced resistance to attacks and increased security.

- **Static Rcon Values:** Rcon values have been expanded to support 12 rounds, allowing flexibility in key expansion without the need for dynamic generation.


- **Fixed Block Size:** This implementation enforces a fixed block size of 16 bytes, and it does not support padding. Input data must be exactly 16 bytes in length.


- **Incompatibility with Standard AES-128:** Please note that this custom AES-128 implementation with 12 rounds is not compatible with the standard AES-128 algorithm, which uses only 10 rounds. Data encrypted using this modified version cannot be decrypted using the standard AES-128 algorithm.

## Usage

To utilize this custom AES-128 implementation with 12 rounds, follow the instructions provided below:

### Include "AES.h" in Your Code

Before using the AES encryption and decryption functions, make sure to include the "AES.h" header in your code.

```c
#include "AES.h"
```

### AES Context

Before using the AES encryption and decryption functions, you need to initialize an AES context. This context stores the encryption/decryption state.

```c
AES_CTX ctx;
```

### Initialize Encryption

To perform encryption, initialize the AES context and provide the encryption key.

```c
AES_EncryptInit(&ctx, key);
```

### Encryption Function

The AES encryption function allows you to encrypt a single 16-byte block.

```c
AES_Encrypt(&ctx, plaintext, ciphertext);
```

### Initialize Decryption

To perform decryption, initialize the AES context with the same key used for encryption.

```c
AES_DecryptInit(&ctx, key);
```

### Decryption Function

The AES decryption function allows you to decrypt a single 16-byte block.

```c
AES_Decrypt(&ctx, ciphertext, plaintext);
```

## Contributions

Contributions and feedback are welcome! If you find issues or have ideas for improvements, please open an issue or submit a pull request.

## License

This custom AES-128 implementation is provided under the [MIT License](./LICENSE).
```

This updated README.md provides detailed instructions on how to use the AES-128 encryption and decryption functions in your custom implementation.
