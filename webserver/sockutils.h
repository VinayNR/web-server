#ifndef SOCK_UTILS_H
#define SOCK_UTILS_H

#include <sys/socket.h>

int createSocket(int);

void bindSocket(int, struct sockaddr *, socklen_t);

void listenOnSocket(int, int);

int acceptConnection(int, struct sockaddr *);

void inline setSocketOptions(int, int, int *);

#endif