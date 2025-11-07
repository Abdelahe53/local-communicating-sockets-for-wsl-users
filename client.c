// create a socket()
// create a connection using connect()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MY_SOCK_PATH "/tmp/serverpath"

#define handle_error(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

int main()
{
    int sockfd, client_connect;
    struct sockaddr_un server_addr;

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1)
        handle_error("client socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, MY_SOCK_PATH, sizeof(server_addr.sun_path) - 1);

    client_connect = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (client_connect == -1)
        handle_error("connect");

    printf("Client successfully connected to server!\n");
}