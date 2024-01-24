// This is an autogenerated config file, any changes to this file will be overwritten

#ifndef SLI_PSA_CONFIG_AUTOGEN_H
#define SLI_PSA_CONFIG_AUTOGEN_H

#define PSA_WANT_KEY_TYPE_AES
#define PSA_WANT_ALG_CCM
#define PSA_WANT_ALG_ECB_NO_PADDING
#define PSA_WANT_ALG_CMAC
#define PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR
#define PSA_WANT_ECC_SECP_R1_256
#define PSA_WANT_ALG_ECDH
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

#define MBEDTLS_PSA_KEY_SLOT_COUNT (2 + 1 + SL_PSA_KEY_USER_SLOT_COUNT)
#ifndef SL_PSA_ITS_MAX_FILES
#define SL_PSA_ITS_MAX_FILES (1 + SL_PSA_ITS_USER_MAX_FILES)
#endif

#endif // SLI_PSA_CONFIG_AUTOGEN_H
