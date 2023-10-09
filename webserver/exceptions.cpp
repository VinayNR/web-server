#include "exceptions.h"

#include <iostream>

using namespace std;

void handleException(int exception_status) {
    switch (exception_status) {
        case SOCKET_EXCPETION:
            perror("Socket excpetion");
            break;
        case BIND_EXCEPTION:
            perror("bind");
            break;
        case LISTEN_EXCPETION:
            perror("listen");
            break;
        case ACCEPT_EXCPETION:
            perror("accept");
            break;
    }
}