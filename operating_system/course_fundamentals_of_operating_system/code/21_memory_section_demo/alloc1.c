#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int destination_port;
    int packet_length;
} Packet;

int main() {

    // Note: Reduced number of packets, otherwise I got an Stack Overflow

    Packet *packets[10000];
    for (int i = 0; i < 10000; i++) {
        packets[i] = (Packet *)malloc(sizeof(Packet));
        // You can initialize the packet fields here, if needed
    }

    // Use the packets here

    // Free the allocated memory
    for (int i = 0; i < 10000; i++) {
        free(packets[i]);
    }

    return 0;
}

