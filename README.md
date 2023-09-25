# AES-128-ECB
This GitHub repository contains two header files for AES-128 ECB encryption: one for the standard AES-128 ECB algorithm and another for a modified version with 12 rounds instead of the standard 10. Enhance your project's security by choosing between the two variants.

## Example standard aes 128 ecb

```c
#include <stdio.h>
#include "aes_standard_rolled.h"

int main() {
	uint8_t key[AES_KEY_SIZE];
	uint8_t data[AES_BLOCK_SIZE];
	
	memcpy(key, "This is aes key!", AES_KEY_SIZE);
	memcpy(data, "This is aes ecb!", AES_BLOCK_SIZE);
	
	uint32_t roundkey[AES_10_ROUND_KEYS];
	
	printf("Original:  ");
	for (uint8_t index = 0; index < AES_BLOCK_SIZE; index++) {
		printf("%02X", data[index]);
	}
	printf("\n");
	
	AesEncryptExpand(roundkey, key);
	
	AesEncrypt(roundkey, data, data);
	
	printf("Encrypted: ");
	for (uint8_t index = 0; index < AES_BLOCK_SIZE; index++) {
		printf("%02X", data[index]);
	}
	printf("\n");
	
        AesDecryptExpand(roundkey, key);
	
	AesDecrypt(roundkey, data, data);
	
	printf("Decrypted: ");
	for (uint8_t index = 0; index < AES_BLOCK_SIZE; index++) {
		printf("%02X", data[index]);
	}
	printf("\n");
	
	
	return 0;
}
```

