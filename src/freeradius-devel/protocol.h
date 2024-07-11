#ifndef FR_PROTOCOL_H
#define FR_PROTOCOL_H

/*
 * heap.h	Structures and prototypes for plug-in protocols
 * Version:	$Id$
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * Copyright 2013 Alan DeKok
 */

RCSIDH(protocol_h, "$Id$")

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	We'll use this below.
 */
typedef int (*rad_listen_parse_t)(CONF_SECTION *, rad_listen_t *);
typedef void (*rad_listen_free_t)(rad_listen_t *);

typedef struct fr_protocol_t {
	uint64_t 		magic;	//!< Used to validate loaded library
	char const		*name;	//!< The name of the protocol, auth, acct...
	size_t			inst_size; //listen section解析后的数据存储结构（listen_socket_t）的大小
	CONF_PARSER		*proto_config;

	rad_listen_parse_t	parse; //解析listen section中的配置项
	rad_listen_free_t	free;
	rad_listen_recv_t	recv;
	rad_listen_send_t	send;
	rad_listen_print_t	print;
	rad_listen_encode_t	encode; //vp转网络属性，发送用
	rad_listen_decode_t	decode; //网络属性转vp，接收用
} fr_protocol_t;

/*
 *	@todo: fix for later
 */
int common_socket_parse(CONF_SECTION *cs, rad_listen_t *this);
int common_socket_print(rad_listen_t const *this, char *buffer, size_t bufsize);


#ifdef __cplusplus
}
#endif

#endif /* FR_PROTOCOL_H */
