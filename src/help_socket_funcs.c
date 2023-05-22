#include "help_socket_funcs.h"
#include <stdlib.h>

/*
 * socket_inet_stream calls socket(AF_INET, SOCK_STREAM, 0) and return result
 * if result < 0 then exit with message.
 * Lol, you see that without this description :D
 */
int socket_inet_stream()
{
	int ls;
	if ((ls = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Listen socket\n");
		exit(EXIT_FAILURE);
	}
	return ls;
}

/*
 * It's just for perfectionism :D
 */
void Setsockopt_reuseaddr(int s)
{
	int optval = 1;
	setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (const void*)&optval, sizeof(optval));
}

/*
 * Bind calls bind for socket and address, handling error with message and exit
*/
void Bind(int s, sa_in *s_addr)
{
	socklen_t s_addr_len = sizeof(*s_addr);
	if (bind(s, (const sa*)s_addr, s_addr_len) < 0) {
		perror("Bind\n");
		exit(EXIT_FAILURE);
	}
}

/*
 * listen_15 like Setsockopt_reuseaddr, just for clean code in main function :)
 */
void Listen_15(int s)
{
	if (listen(s, 15) < 0) {
		perror("Listen\n");
		exit(EXIT_FAILURE);
	}
}

/*
 * Set address ip any + af_inet + 8080 port.
 */
sa_in inet_8080_inaddr_any()
{
	sa_in s_addr;
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(8080);
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	return s_addr;
}

/*
 * I dont need to know connect address so I set NULL for address structure
 * and handling error.
 */
int Accept_null_addr(int s)
{
	int cs;
	if ((cs = accept(s, NULL, NULL)) < 0) {
		perror("Accept\n");
		exit(EXIT_FAILURE);
	}
	return cs;
}

/*
 * Recv_0_flags does recv and check error + exit if < 0, returns recv return bytes.
 */
ssize_t Recv_0_flags(int cs, char *buf, size_t buf_len)
{
	ssize_t recv_return;
	if ((recv_return = recv(cs, buf, buf_len, 0)) < 0) {
		perror("Recv\n");
		exit(EXIT_FAILURE);
	}
	return recv_return;
}

/*
 * Send_0_flags does send and check errors + exit if < 0, returns send return bytes
 */
ssize_t Send_0_flags(int cs, const char *buf, size_t buf_len)
{
	ssize_t send_return = send(cs, buf, buf_len, 0);
	if (send_return < 0) {
		perror("Send\n");
		exit(EXIT_FAILURE);
	}
	return send_return;
}
