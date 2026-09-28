#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SOCKETERROR (-1)
int 
check(int exp, const char* message)
{
    if (exp == SOCKETERROR) {
        perror(message);
        exit(EXIT_FAILURE);
    }
    return exp;
}

unsigned char
parity_check(char* data)
{
    char parity = 0;
    for(const char* p = data; *p; p++) {
        if (*p != '1' && *p != '0') {
            return 0xFF;
        }
        parity ^= (*p - '0');
    }
    return parity;
}

int
main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int my_port = atoi(argv[1]);
    int rx_socket;
    struct sockaddr_in peer_addr;
    struct sockaddr_in my_addr = {.sin_family = AF_INET,
                                    .sin_addr.s_addr = INADDR_ANY,
                                    .sin_port = htons(my_port)};

    char buffer[BUFFER_SIZE];

    if ((rx_socket = socket(AF_INET, SOCK_DGRAM, 0)) <= 0) {
        perror("Failded to create socket!");
        return EXIT_FAILURE;
    }

    // bind socket to address port
    int result = bind(rx_socket, (struct sockaddr*)&my_addr, sizeof(my_addr));
    check(result, "Could not bind");

    socklen_t address_length = sizeof(peer_addr);
    int bytes_received = recvfrom(rx_socket, buffer, BUFFER_SIZE, 0, 
        (struct sockaddr*)&peer_addr,&address_length);

    if (bytes_received < 2) {
        perror("Received packet too short");
        return EXIT_FAILURE;
    }

    unsigned char recv_parity = buffer[0];
    char* payload = (char*)(buffer + 1);
    unsigned char parity = parity_check(payload);

    check(bytes_received, "Recvfrom failed");

    printf("Received a package from %s:%d -- Message = %s\n", 
        inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port), payload);

    printf("Check: %s\n", (recv_parity == parity)?"OK":"MISMATCH");

    close(rx_socket);

    return EXIT_SUCCESS;
}
