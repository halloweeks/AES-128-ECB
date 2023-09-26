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

### Example Code (main.c)

Here's an example code snippet in C for using this custom AES-128 implementation:

```c
#include <stdio.h>
#include "AES.h"

void output(const char* title, uint8_t *data) {
	printf("%s", title);
	for (uint8_t index = 0; index < AES_BLOCK_SIZE; index++) {
		printf("%02X", data[index]);
	}
	printf("\n");
}

int main(int argc, const char *argv[]) {
	uint8_t key[AES_KEY_SIZE];
	uint8_t data[AES_BLOCK_SIZE];
	
	memcpy(key, "This is aes key!", AES_KEY_SIZE);
	memcpy(data, "This is test msg", AES_BLOCK_SIZE);
	
	output("Original:  ", data);
	
	AES_CTX ctx;
	
	AES_EncryptInit(&ctx, key);
	
	AES_Encrypt(&ctx, data, data);
	
	output("Encrypted: ", data);
	
	AES_DecryptInit(&ctx, key);
	
	AES_Decrypt(&ctx, data, data);
	
	output("Decrypted: ", data);
	return 0;
}
```

## Contributions

Contributions and feedback are welcome! If you find issues or have ideas for improvements, please open an issue or submit a pull request.

## License

This custom AES-128 implementation is provided under the [MIT License](./LICENSE).
