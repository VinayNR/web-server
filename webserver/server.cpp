#include <iostream>
#include <fstream>
#include <cerrno>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>

#include "sockutils.h"
#include "exceptions.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc != 2) {
        cout << "Usage error: <executable> <port>" << endl;
        return 1;
    }

    // Get the device's ip address
    int status;
    struct addrinfo hints;
    struct addrinfo *addressinfo;

    // set the hints needed
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // get the address info
    if ((status = getaddrinfo(NULL, argv[1], &hints, &addressinfo)) != 0) {
        cerr << "Error with get address info on server: " << gai_strerror(status) << endl;
        return 1;
    }

    cout << "Address information obtained" << endl;
    // create a sockaddr_in structure and extract the server address
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)addressinfo->ai_addr;

    // socket file descriptor for listening to client connections
    int listen_sockfd;
    int max_client_connections = 20;
    try {
        // create a TCP socket and get a descriptor
        listen_sockfd = createSocket(SOCK_STREAM);

        // bind the socket to the local port
        bindSocket(listen_sockfd, addressinfo->ai_addr, addressinfo->ai_addrlen);

        // listen on the socket for incoming connections
        listenOnSocket(listen_sockfd, max_client_connections);

    } catch (int exception_status) {
        handleException(exception_status);
        return -1;
    }

    cout << "Server listening on port: " << argv[1] << endl;

    // store client address during incoming connect requests
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof client_addr;

    // loop for incomfing client connections
    while (true) {
        // accept a client connection
        int client_fd = acceptConnection(listen_sockfd, (struct sockaddr *)&client_addr);
    }
}