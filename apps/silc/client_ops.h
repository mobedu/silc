/*

  client_ops.h

  Author: Pekka Riikonen <priikone@poseidon.pspt.fi>

  Copyright (C) 2000 Pekka Riikonen

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

*/

#ifndef CLIENT_OPS_H
#define CLIENT_OPS_H

void silc_say(SilcClient client, SilcClientConnection conn, char *msg, ...);
void silc_op_say(SilcClient client, SilcClientConnection conn, 
		 SilcClientMessageType type, char *msg, ...);
void silc_channel_message(SilcClient client, SilcClientConnection conn,
			  SilcClientEntry sender, 
			  SilcChannelEntry channel, 
			  SilcMessageFlags flags, char *msg);
void silc_private_message(SilcClient client, SilcClientConnection conn,
			  SilcClientEntry sender, 
			  SilcMessageFlags flags, char *msg);
void silc_notify(SilcClient client, SilcClientConnection conn, 
		 SilcNotifyType type, ...);
void silc_command(SilcClient client, SilcClientConnection conn, 
		  SilcClientCommandContext cmd_context, int success,
		  SilcCommand command);
void silc_command_reply(SilcClient client, SilcClientConnection conn,
			SilcCommandPayload cmd_payload, int success,
			SilcCommand command, SilcCommandStatus status, ...);
void silc_connect(SilcClient client, SilcClientConnection conn, int success);
void silc_disconnect(SilcClient client, SilcClientConnection conn);
void silc_ask_passphrase(SilcClient client, SilcClientConnection conn,
			 SilcAskPassphrase completion, void *context);
void silc_verify_public_key(SilcClient client, SilcClientConnection conn,
			    SilcSocketType conn_type, unsigned char *pk, 
			    SilcUInt32 pk_len, SilcSKEPKType pk_type,
			    SilcVerifyPublicKey completion, void *context);
int silc_get_auth_method(SilcClient client, SilcClientConnection conn,
			 char *hostname, SilcUInt16 port,
			 SilcProtocolAuthMeth *auth_meth,
			 unsigned char **auth_data,
			 SilcUInt32 *auth_data_len);
void silc_failure(SilcClient client, SilcClientConnection conn, 
		  SilcProtocol protocol, void *failure);
int silc_key_agreement(SilcClient client, SilcClientConnection conn,
		       SilcClientEntry client_entry, char *hostname,
		       int port,
		       SilcKeyAgreementCallback *completion,
		       void **context);
#endif
