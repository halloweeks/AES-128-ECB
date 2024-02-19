## Overview

This GitHub repository contains a standard implementation of the Advanced Encryption Standard (AES) with a focus on AES-128 ECB (Electronic Codebook) encryption. AES-128 is a widely adopted encryption standard known for its security and efficiency.

## Features

- **AES-128 ECB:** This implementation adheres to the AES-128 ECB encryption mode, which encrypts individual 16-byte blocks of data independently. It supports the encryption of multiple 16-byte blocks in sequence.

- **Fixed Block Size:** The algorithm enforces a fixed block size of 16 bytes, and it does not support padding. Input data must be exactly 16 bytes in length for each block.

- **Compatibility:** Data encrypted using this standard AES-128 ECB algorithm can be decrypted using any compliant AES-128 ECB decryption implementation.

## Usage

To utilize this standard AES-128 ECB implementation, follow the instructions provided below:

### Including "AES_128_ECB.h" Header

Before utilizing the AES encryption and decryption functions, ensure that you've included the "AES_128_ECB.h" header in your code. This header provides access to the AES functionality.

```c
#include "AES_128_ECB.h"
```

### AES Context Initialization

To perform AES encryption and decryption, you must initialize an AES context. This context serves as a container for maintaining the encryption and decryption state.

```c
AES_CTX ctx;
```

### Initialize Encryption

To perform encryption, initialize the AES context and provide the encryption key.

```c
AES_EncryptInit(&ctx, key);
```

### Encryption Function

The AES encryption function allows you to encrypt a single blocks of data. Each block must be exactly 16 bytes in size, and this implementation does not support padding. Ensure that you provide data blocks of precisely 16 bytes each for encryption.

```c
AES_Encrypt(&ctx, plaintext, plaintext_size, ciphertext);
```

### Initialize Decryption

To perform decryption, initialize the AES context with the same key used for encryption.

```c
AES_DecryptInit(&ctx, key);
```

### Decryption Function

The AES decryption function allows you to decrypt a single blocks of data. Each block must be exactly 16 bytes in size, and this implementation does not support padding. Ensure that you provide ciphertext blocks of precisely 16 bytes each for decryption.

```c
AES_Decrypt(&ctx, ciphertext, ciphertext_size, plaintext);
```

### Encryption and Decryption Function Completion

After you have finished using the AES encryption and decryption functions and no longer require the AES context, it's essential to clear sensitive information from memory. Use the following function to achieve this:

```c
AES_CTX_Free(&ctx);
```

### Example Code (main.c)

Here's an example code snippet in C for using this standard AES-128 ECB implementation:

```c
#include <stdio.h>
#include "AES_128_ECB.h"

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
	
	AES_CTX_Free(&ctx);
	return 0;
}
```

## Contributions

Contributions and feedback are welcome! If you find issues or have ideas for improvements, please open an issue or submit a pull request.

## License

This standard AES-128 ECB implementation is provided under the [MIT License](./LICENSE).
