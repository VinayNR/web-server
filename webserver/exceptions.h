#ifndef EXCPETIONS_H
#define EXCPETIONS_H

#define SOCKET_EXCPETION 1
#define BIND_EXCEPTION 2
#define LISTEN_EXCPETION 3
#define ACCEPT_EXCPETION 4

void handleException(int);

#endif