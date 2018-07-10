/*
 * Copyright (C) Ambroz Bizjak <ambrop7@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <system/BReactor.h>
#include <flow/PacketPassInterface.h>
#include <flow/PacketPassConnector.h>

// connection buffer size for sending to client, in packets
#define CONNECTION_CLIENT_BUFFER_SIZE 1

// connection buffer size for sending to UDP, in packets
#define CONNECTION_UDP_BUFFER_SIZE 1

// maximum connections for client
#define DEFAULT_MAX_CONNECTIONS_FOR_CLIENT 35

// SO_SNDBFUF socket option for clients, 0 to not set
#define CLIENT_DEFAULT_SOCKET_SEND_BUFFER 1048576

void udpgw_init (int argc, char **argv, BReactor* udpgw_reactor, int udp_mtu_);

PacketPassInterface* udpgw_get_input ();
PacketPassConnector* udpgw_get_output ();

void udpgw_cleanup ();
