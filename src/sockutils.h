#ifndef SOCK_UTILS_H
#define SOCK_UTILS_H

#include <sys/socket.h>

#define SOCKET_FAILURE -1

inline int createSocket(int);

inline int bindSocket(int, struct sockaddr *, socklen_t);

inline int listenOnSocket(int, int);

inline int acceptConnection(int, struct sockaddr *);

inline void setSocketOptions(int, int, int *);

int checkSocketOperation(int, char *);

#endif