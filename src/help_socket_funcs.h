#ifndef HELP_SOCKET_FUNCS_H_HTTP
#define HELP_SOCKET_FUNCS_H_HTTP

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>
#include <string.h>

typedef struct sockaddr sa;
typedef struct sockaddr_in sa_in;
typedef struct pollfd pf;

int socket_inet_stream();
void Setsockopt_reuseaddr(int s);
void Bind(int s, sa_in *s_addr);
void Listen_15(int s);
sa_in inet_8080_inaddr_any();
int Accept_null_addr(int s);
ssize_t Recv_0_flags(int cs, char *buf, size_t buf_len);

#endif
