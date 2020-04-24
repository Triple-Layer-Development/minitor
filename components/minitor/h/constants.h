#ifndef MINITOR_CONSTANTS
#define MINITOR_CONSTANTS

#define MINITOR_TAG "MINITOR"

#define H_LENGTH 32
#define ID_LENGTH 20
#define G_LENGTH 32
#define DIGEST_LEN 20

#define HSDIR_INTERVAL_DEFAULT 1440
#define HSDIR_N_REPLICAS_DEFAULT 2
#define HSDIR_SPREAD_STORE_DEFAULT 4

#define SERVER_STR "Server"
#define SERVER_STR_LENGTH 6

#define PROTOID "ntor-curve25519-sha256-1"
#define PROTOID_LENGTH 24
#define PROTOID_MAC PROTOID ":mac"
#define PROTOID_MAC_LENGTH PROTOID_LENGTH + 4
#define PROTOID_KEY PROTOID ":key_extract"
#define PROTOID_KEY_LENGTH PROTOID_LENGTH + 12
#define PROTOID_VERIFY PROTOID ":verify"
#define PROTOID_VERIFY_LENGTH PROTOID_LENGTH + 7
#define PROTOID_EXPAND PROTOID ":key_expand"
#define PROTOID_EXPAND_LENGTH PROTOID_LENGTH + 11

#define HS_PROTOID "tor-hs-ntor-curve25519-sha3-256-1"
#define HS_PROTOID_LENGTH 33
#define HS_PROTOID_MAC HS_PROTOID ":hs_mac"
#define HS_PROTOID_MAC_LENGTH HS_PROTOID_LENGTH + 7
#define HS_PROTOID_KEY HS_PROTOID ":hs_key_extract"
#define HS_PROTOID_KEY_LENGTH HS_PROTOID_LENGTH + 15
#define HS_PROTOID_VERIFY HS_PROTOID ":hs_verify"
#define HS_PROTOID_VERIFY_LENGTH HS_PROTOID_LENGTH + 10
#define HS_PROTOID_EXPAND HS_PROTOID ":hs_key_expand"
#define HS_PROTOID_EXPAND_LENGTH HS_PROTOID_LENGTH + 14

#define SECRET_INPUT_LENGTH 32 * 5 + ID_LENGTH + PROTOID_LENGTH
#define AUTH_INPUT_LENGTH 32 * 4 + ID_LENGTH + PROTOID_LENGTH + SERVER_STR_LENGTH

#endif
