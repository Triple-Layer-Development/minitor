#ifndef MINITOR_CONNECTIONS_H
#define MINITOR_CONNECTIONS_H

#include "./structures/circuit.h"
#include "./structures/connections.h"

extern SemaphoreHandle_t connections_mutex;
extern SemaphoreHandle_t connection_access_mutex[16];
extern DlConnection* connections;

void v_cleanup_connection( DlConnection* dl_connection );
int d_attach_or_connection( uint32_t address, uint16_t port, OnionCircuit* circuit );
int d_create_local_connection( uint32_t circ_id, uint16_t stream_id, uint16_t port );
int d_forward_to_local_connection( uint32_t circ_id, uint32_t stream_id, uint8_t* data, uint32_t length );
void v_cleanup_local_connection( uint32_t circ_id, uint32_t stream_id );
void v_cleanup_local_connections_by_circ_id( uint32_t circ_id );
bool b_verify_or_connection( uint32_t id );
void v_dettach_connection( DlConnection* or_connection );
DlConnection* px_get_conn_by_id_and_lock( uint32_t id );

#endif
