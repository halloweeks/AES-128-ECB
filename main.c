#include <stdio.h>

/** This is standard version of aes 128 ecb, 10 round **/
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
