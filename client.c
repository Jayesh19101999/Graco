// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"  // Localhost
#define PORT 8080
#define MAX_BUFFER 1024

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send a message to the server
    const char *message = "Hello from client!";
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Read response from the server
    read(sock, buffer, MAX_BUFFER);
    printf("Server: %s\n", buffer);

    // Close the connection
    close(sock);
    return 0;
}

