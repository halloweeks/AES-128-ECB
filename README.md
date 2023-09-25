# AES-128-ECB
This GitHub repository contains two header files for AES-128 ECB encryption: one for the standard AES-128 ECB algorithm and another for a modified version with 12 rounds instead of the standard 10. Enhance your project's security by choosing between the two variants.

## Example standard aes 128 ecb

## Include header


```c
#include "aes_standard_rolled.h"
```
OR
```c
#include "aes_standard_unrolled.h"
```

```c
#include <stdio.h>

/** That is standard version of aes 128 ecb, 10 round **/
#include "aes_standard_rolled.h"

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
	uint32_t roundkey[AES_10_ROUND_KEYS];
	
	memcpy(key, "This is aes key!", AES_KEY_SIZE);
	memcpy(data, "This is aes ecb!", AES_BLOCK_SIZE);
	
	output("Original:  0x", data);
	
	AesEncryptExpand(roundkey, key);
	AesEncrypt(roundkey, data, data);
	
	output("Encrypted: 0x", data);
	
	AesDecryptExpand(roundkey, key);
	AesDecrypt(roundkey, data, data);
	
	output("Decrypted: 0x", data);
	return 0;
}
```

## Example modified version of aes 128 ecb 

##include header

```
#include "aes_modified_rolled.h"
```
OR
```
#include "aes_modified_unrolled.h
```

```c
#include <stdio.h>

/** That is modified version of aes 128 ecb, modified 10 round to 12 **/
#include "aes_modified_rolled.h"

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
	uint32_t roundkey[AES_12_ROUND_KEYS];
	
	memcpy(key, "This is aes key!", AES_KEY_SIZE);
	memcpy(data, "This is aes ecb!", AES_BLOCK_SIZE);
	
	output("Original:  0x", data);
	
	AesEncryptExpand(roundkey, key);
	AesEncrypt(roundkey, data, data);
	
	output("Encrypted: 0x", data);
	
	AesDecryptExpand(roundkey, key);
	AesDecrypt(roundkey, data, data);
	
	output("Decrypted: 0x", data);
	return 0;
}
```

