#include "help_socket_funcs.h"
#include "request_handling.h"

enum lens {
	brs_len = 1450, /* length for recv and send bufs (brs - buf recv/send) */
};

static char buf_recv[brs_len];
static char buf_send[brs_len];

static const char h404[] = "HTTP/1.1 404\r\n\
Version: HTTP/1.1\r\n\
Content-Type: text/html\r\n\
Content-Length: 13\r\n\r\n\
<h1>404</h1>\n";
static const char h200[] = "HTTP/1.1 200\r\n\
Version: HTTP/1.1\r\n\
Content-Type: text/html\r\n\
Content-Length: ";

int main()
{
	int ls = socket_inet_stream();
	Setsockopt_reuseaddr(ls);
	sa_in ls_addr = inet_8080_inaddr_any();
	Bind(ls, &ls_addr);
	Listen_15(ls);

 	/* without \0 symbol */
	const size_t h404_len = sizeof(h404) - 1;
	const size_t h200_len = sizeof(h200) - 1;
	/* without \0 symbol */

	/* main loop */
	while (1) {
		int cs = Accept_null_addr(ls);
		ssize_t recv_return = Recv_0_flags(cs, buf_recv, brs_len);
		buf_recv[recv_return] = 0;
		
		const char *request_file_name = get_request_file_name(buf_recv);
		int request_file_length = get_request_file_length(request_file_name);
		if (request_file_length < 0) {
			Send_0_flags(cs, h404, h404_len);
			close(cs);
			continue;
		}

		/* Forming response and send */
		Send_0_flags(cs, h200, h200_len);
		char rfl_string[15] = {0}; /* rfl_string declared to contain request_file_length as string */
		int snprintf_return = snprintf(rfl_string, 14, "%d\r\n\r\n", request_file_length);
		Send_0_flags(cs, (const char*)rfl_string, snprintf_return);
		/* Forming response and send */

		close(cs);
	}
	/* main loop */

	exit(EXIT_SUCCESS);
}
