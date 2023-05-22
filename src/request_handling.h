#ifndef REQUEST_HANDLING_H_HTTP
#define REQUEST_HANDLING_H_HTTP

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

const char *get_request_file_name(char *buf_recv);
int get_request_file_length(const char *rfn);

#endif
