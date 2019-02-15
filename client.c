#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct addrinfo *address;
    getaddrinfo(argv[1], argv[2], NULL, &address);
    connect(sockfd, address->ai_addr, address->ai_addrlen);
    freeaddrinfo(address);
    close(sockfd);
    return 0;
}
