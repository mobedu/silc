/*

  protocol.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2003 Pekka Riikonen

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

*/

#ifndef PROTOCOL_H
#define PROTOCOL_H

/* SILC client protocol types */
#define SILC_PROTOCOL_SERVER_NONE               0
#define SILC_PROTOCOL_SERVER_CONNECTION_AUTH    1
#define SILC_PROTOCOL_SERVER_KEY_EXCHANGE       2
#define SILC_PROTOCOL_SERVER_REKEY              3
#define SILC_PROTOCOL_SERVER_BACKUP             4
/* #define SILC_PROTOCOL_SERVER_MAX             255 */

/* Internal context for Key Exchange protocol. */
typedef struct {
  void *server;
  void *context;
  SilcSocketConnection sock;
  SilcRng rng;

  /* TRUE if we are receiveing part of the protocol */
  bool responder;

  /* Destinations ID taken from authenticataed packet so that we can
     get the destinations ID. */
  void *dest_id;
  SilcIdType dest_id_type;

  /* Pointers to the configurations. Defined only when responder is TRUE */
  SilcServerConfigRef cconfig;
  SilcServerConfigRef sconfig;
  SilcServerConfigRef rconfig;

  SilcTask timeout_task;
  SilcPacketContext *packet;
  SilcSKESecurityPropertyFlag flags;
  SilcSKE ske;
  SilcSKEKeyMaterial *keymat;
} SilcServerKEInternalContext;

/* Internal context for connection authentication protocol */
typedef struct {
  void *server;
  void *context;
  SilcSocketConnection sock;

  /* TRUE if we are receiving part of the protocol */
  bool responder;

  /* SKE object from Key Exchange protocol. */
  SilcSKE ske;

  /* Authentication method and data if we alreay know it. This is filled
     before starting the protocol if we know the authentication data.
     Otherwise these are and remain NULL. Used when we are initiating. */
  SilcUInt32 auth_meth;
  void *auth_data;
  SilcUInt32 auth_data_len;

  /* Destinations ID from KE protocol context */
  void *dest_id;
  SilcIdType dest_id_type;

  /* Pointers to the configurations. Defined only when responder is TRUE */
  SilcServerConfigRef cconfig;
  SilcServerConfigRef sconfig;
  SilcServerConfigRef rconfig;

  SilcTask timeout_task;
  SilcPacketContext *packet;
  SilcUInt16 conn_type;
} SilcServerConnAuthInternalContext;

/* Internal context for the rekey protocol */
typedef struct {
  void *server;
  void *context;
  SilcSocketConnection sock;
  bool responder;		    /* TRUE if we are receiving party */
  bool pfs;			    /* TRUE if PFS is to be used */
  SilcSKE ske;			    /* Defined if PFS is used */
  SilcPacketContext *packet;
  SilcTask timeout_task;
} SilcServerRekeyInternalContext;

/* Prototypes */
void silc_server_protocols_register(void);
void silc_server_protocols_unregister(void);
int silc_server_protocol_ke_set_keys(SilcServer server,
				     SilcSKE ske,
				     SilcSocketConnection sock,
				     SilcSKEKeyMaterial *keymat,
				     SilcCipher cipher,
				     SilcPKCS pkcs,
				     SilcHash hash,
				     SilcHmac hmac,
				     SilcSKEDiffieHellmanGroup group,
				     bool is_responder);

#endif