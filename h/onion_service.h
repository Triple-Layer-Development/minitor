/*
Copyright (C) 2022 Triple Layer Development Inc.

Minitor is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

Minitor is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef MINITOR_ONION_SERVICE_H
#define MINITOR_ONION_SERVICE_H

#include "wolfssl/wolfcrypt/settings.h"
#include "wolfssl/wolfcrypt/curve25519.h"
#include "wolfssl/wolfcrypt/ed25519.h"

#include "./structures/onion_service.h"
#include "./structures/circuit.h"
#include "./structures/onion_message.h"
#include "./structures/cell.h"

//void v_handle_onion_service( void* pv_parameters );
void v_onion_service_handle_local_tcp_data( OnionCircuit* circuit, DlConnection* or_connection, ServiceTcpTraffic* tcp_traffic );
void v_onion_service_handle_cell( OnionCircuit* circuit, DlConnection* or_connection, Cell* relay_cell );
int d_onion_service_handle_relay_data( OnionService* onion_service, Cell* unpacked_cell );
int d_onion_service_handle_relay_begin( OnionCircuit* rend_circuit, DlConnection* or_connection, Cell* begin_cell );
//int d_onion_service_handle_relay_end( OnionService* onion_service, Cell* unpacked_cell );
int d_onion_service_handle_relay_truncated( OnionCircuit* rend_circuit, DlConnection* or_connection, Cell* truncated_cell );
void v_handle_local( void* pv_parameters );
int d_onion_service_handle_introduce_2( OnionCircuit* intro_circuit, Cell* unpacked_cell );
int d_router_join_rendezvous( OnionCircuit* rend_circuit, DlConnection* or_connection, unsigned char* rendezvous_cookie, unsigned char* hs_pub_key, unsigned char* auth_input_mac );
int d_verify_and_decrypt_introduce_2( OnionService* onion_service, Cell* introduce_cell, uint8_t num_extensions, uint8_t* client_pk, uint8_t* encrypted_data, OnionCircuit* intro_circuit, curve25519_key* client_handshake_key );
int d_hs_ntor_handshake_finish( uint8_t* auth_pub_key, curve25519_key* encrypt_key, curve25519_key* hs_handshake_key, curve25519_key* client_handshake_key, HsCrypto* hs_crypto, uint8_t* auth_input_mac, bool is_client );
DoublyLinkedOnionRelayList* px_get_target_relays( unsigned int hsdir_n_replicas, unsigned char* blinded_pub_key, int time_period, unsigned int hsdir_interval, unsigned int hsdir_spread_store, int next );
//int d_send_descriptors( unsigned char* descriptor_text, int descriptor_length, DoublyLinkedOnionRelayList* target_relays );
//int d_post_descriptor( unsigned char* descriptor_text, int descriptor_length, OnionCircuit* publish_circuit );
int d_generate_outer_descriptor( char* filename, ed25519_key* descriptor_signing_key, long int valid_after, ed25519_key* blinded_key, int revision_counter );
int d_generate_first_plaintext( char* filename );
int d_encrypt_descriptor_plaintext( char* filename, unsigned char* secret_data, int secret_data_length, const char* string_constant, int string_constant_length, unsigned char* sub_credential, int64_t revision_counter );
int d_generate_second_plaintext( char* filename, OnionCircuit** intro_circuits, long int valid_after, ed25519_key* descriptor_signing_key );
void v_generate_packed_link_specifiers( OnionRelay* relay, unsigned char* packed_link_specifiers );
int d_generate_packed_crosscert( char* destination, unsigned char* certified_key, ed25519_key* signing_key, unsigned char cert_type, uint8_t cert_key_type, long int valid_after );
void v_ed_pubkey_from_curve_pubkey( unsigned char* output, const unsigned char* input, int sign_bit );
int d_router_establish_intro( OnionCircuit* circuit, DlConnection* or_connection );
int d_derive_blinded_key( ed25519_key* blinded_key, ed25519_key* master_key, int64_t period_number, int64_t period_length, unsigned char* secret, int secret_length );
int d_generate_hs_keys( OnionService* onion_service, const char* onion_service_directory );
int d_begin_hsdir( OnionCircuit* publish_circuit, DlConnection* or_connection );
int d_post_hs_desc( OnionCircuit* publish_circuit, DlConnection* or_connection );
int d_push_hsdir();
void v_cleanup_service_hs_data( OnionService* service, int desc_index );

#endif
