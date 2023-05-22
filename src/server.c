#include "help_socket_funcs.h"
#include "request_handling.h"

static char buf_recv[1450];
static char buf_send[1450];
static const char header_404[] = "HTTP/1.1 404";

int main()
{
	int ls = socket_inet_stream();
	Setsockopt_reuseaddr(ls);
	sa_in ls_addr = inet_8080_inaddr_any();
	Bind(ls, &ls_addr);
	Listen_15(ls);

	while (1) {
		int cs = Accept_null_addr(ls);
		ssize_t recv_return = Recv_0_flags(cs, buf_recv, 1450);
		buf_recv[recv_return] = 0;
		
		const char *request_file_name = get_request_file_name(buf_recv);
		int request_file_length = get_request_file_length(request_file_name);

		/* Forming response */
		/* Forming response */

		close(cs);
	}

	exit(EXIT_SUCCESS);
}
