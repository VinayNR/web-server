#include "sockutils.h"

#include <sys/socket.h>
#include <iostream>

inline int createSocket(int socktype) {
    return socket(AF_INET, socktype, 0);
}

inline int bindSocket(int sockfd, struct sockaddr *address, socklen_t address_length) {
    return bind(sockfd, address, address_length);
}

inline int listenOnSocket(int sockfd, int max_client_connections) {
    return listen(sockfd, max_client_connections);
}

inline int acceptConnection(int sockfd, struct sockaddr *client_addr) {
    socklen_t addr_size = sizeof(client_addr);
    return accept(sockfd, client_addr, &addr_size);
}

inline void setSocketOptions(int sockfd, int optionflag, int * optval) {
    setsockopt(sockfd, SOL_SOCKET, optionflag, (const void *)optval , sizeof(int));
}

int checkSocketOperation(int result, char *msg) {
    if (result == -1) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return result;
}