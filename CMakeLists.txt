cmake_minimum_required(VERSION 3.0)

project(server_http)

set(SRC
	./src/server.c
	./src/help_socket_funcs.c
	./src/request_handling.c
)

set(HEADERS
	./src/help_socket_funcs.h
	./src/request_handling.h
)

add_executable(exe ${SRC} ${HEADERS})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
