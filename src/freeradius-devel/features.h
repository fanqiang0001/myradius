/*
 *	New defines for minimizing the size of the server, to strip
 *	out functionality.
 *
 *	This is a hack and should be removed when the protocols are moved
 *	into individual modules.
 */
#ifndef WITHOUT_PROXY
#  define WITH_PROXY (1)
#else
#  define WITHOUT_COA (1)
#endif

#ifndef WITHOUT_UNLANG
#  define WITH_UNLANG (1)
#endif

#ifndef WITHOUT_ACCOUNTING
#  define WITH_ACCOUNTING (1)
#endif

#ifdef WITH_ACCOUNTING
#  ifndef WITHOUT_DETAIL
#    define WITH_DETAIL (1)
#  endif
#endif

#ifdef WITH_ACCOUNTING
#  ifndef WITHOUT_SESSION_MGMT
#    define WITH_SESSION_MGMT (1)
#  endif
#endif

#ifndef WITHOUT_DYNAMIC_CLIENTS
#  define WITH_DYNAMIC_CLIENTS (1)
#endif

#ifndef WITHOUT_STATS
#  define WITH_STATS
#endif

#ifndef WITHOUT_COMMAND_SOCKET
#  ifdef HAVE_SYS_UN_H
#    define WITH_COMMAND_SOCKET (1)
#  endif
#endif

#ifndef WITHOUT_COA
#  define WITH_COA (1)
#  ifndef WITH_PROXY
#    error WITH_COA requires WITH_PROXY
#  endif
#endif

#ifdef WITHOUT_TLS
#  ifndef HAVE_OPENSSL_SSL_H
#    error TLS requires OpenSSL
#  endif
#else
#  ifdef HAVE_OPENSSL_SSL_H
#    ifndef WITH_TLS
#      ifndef NO_OPENSSL
#        define WITH_TLS (1)
#      endif
#    endif
#  endif
#endif
#define WITH_ASCEND_BINARY 1
#define WITH_DHCP 1
#define WITH_NDEBUG 1
#define WITH_TCP 1
#define WITH_THREADS 1
#define WITH_UDPFROMTO /**/
#define WITH_VMPS 1
#define RADIUSD_VERSION 030021
#define RADIUSD_VERSION_STRING "3.0.21"
