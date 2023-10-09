#include "sockutils.h"
#include "exceptions.h"

#include <sys/socket.h>

int createSocket(int socktype) {
    int listen_sockfd;
    if ((listen_sockfd = socket(AF_INET, socktype, 0)) < 0) {
        throw SOCKET_EXCPETION;
    }
    return listen_sockfd;
}

void bindSocket(int sockfd, struct sockaddr *address, socklen_t address_length) {
    if (bind(sockfd, address, address_length) < 0) {
        throw BIND_EXCEPTION;
    }
}

void listenOnSocket(int sockfd, int max_client_connections) {
    if (listen(sockfd, max_client_connections) < 0) {
        throw LISTEN_EXCPETION;
    }
}

int acceptConnection(int sockfd, struct sockaddr *client_addr) {
    socklen_t addr_size = sizeof(client_addr);
    int client_fd;
    if ((client_fd = accept(sockfd, client_addr, &addr_size)) < 0) {
        throw ACCEPT_EXCPETION;
    }
    return client_fd;
}

void inline setSocketOptions(int sockfd, int optionflag, int * optval) {
    setsockopt(sockfd, SOL_SOCKET, optionflag, (const void *)optval , sizeof(int));
}