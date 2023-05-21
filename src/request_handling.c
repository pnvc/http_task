#include "request_handling.h"

/*
 * get_request_file_name function takes the buffer that has data after recv in main loop.
 * New pointer = buffer pointer.
 * Add to the new pointer 4 and we have the start of the file name that was requested.
 * Then we skip all '/' symbols.
 * Then we look at the start character of that pointer of the file name:
 * 		if ' ' then we makes default index file as "index.html"
 * 		else we place 0 at the next space symbol and have file name with null-terminated symbol.
 * 	Return this pointer (index.html or another name).
 */
const char *get_request_file_name(char *buf_recv)
{
	char *request_file_name = buf_recv + 4;

	while (*request_file_name == '/') {
		request_file_name++;
	}

	if (*request_file_name == ' ') {
		const char index[] = "index.html";
		request_file_name = (char*)calloc(sizeof(index), sizeof(char));
		if (!request_file_name) {
			return NULL;
		}
		strcpy(request_file_name, index);
	} else {
		*strchr(request_file_name, ' ') = 0;
	}

	return (const char*)request_file_name;
}
