#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

unsigned char 
parity_check(const char* data)
{
    char parity = 0;
    for(const char* p = data; *p; p++) {
        if(*p != '0' && *p != '1') {
            return 0xFF;
        }
        parity ^= (*p - '0');
    }
    return parity;
}

void 
noise(char* message, int p)
{
    int roll = rand() % 101;
    if (roll > p) return;

    size_t len = strlen(message);
    if (len == 0) return;
    size_t id = rand() % len;
    message[id] ^= (1 << (rand()%8));
}

int
main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Usage: %s <peer_ip> <peer_port> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // get information from arg
    const char* peer_ip = argv[1];
    int peer_port = atoi(argv[2]);
    const char* message = argv[3];

    struct sockaddr_in peer_addr = {.sin_family = AF_INET, .sin_port = htons(peer_port)};

    if (inet_pton(AF_INET, peer_ip, &(peer_addr.sin_addr)) <= 0) {
        perror("Something wrong with IP address!");
        return EXIT_FAILURE;
    }

    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(udp_socket < 0) {
        perror("Sorry, couldn't create the socket.");
        return EXIT_FAILURE;
    }

    size_t message_len = strlen(message);
    unsigned char buf[1 + message_len + 1];
    unsigned char parity = parity_check(message);
    if(parity == 0xFF) {
        perror("Message must be 0/1 bit string.");
        return EXIT_FAILURE;
    }

    noise((char*)message, 20);

    buf[0] = parity;
    memcpy(buf + 1, message, message_len);
    buf[1 + message_len] = '\0';

    if (sendto(udp_socket, buf, 1 + message_len + 1, 0, 
            (struct sockaddr*) &peer_addr, sizeof(peer_addr)) < 0) {
        perror("Faild to send message.");
        return EXIT_FAILURE;
    }

    printf("Sent \"%s\" to %s:%d\n", message, peer_ip, peer_port);
    close(udp_socket);

    return EXIT_SUCCESS;
}
