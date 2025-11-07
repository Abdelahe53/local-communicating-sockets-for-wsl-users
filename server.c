// 1. create a tcp socket
// 2. bind(2) the socket to a local address and port
// 3. call listen(2) to put the socket into the listeninig state
// 4. accept incoming connections using accept(2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MY_SOCK_PATH "/tmp/serverpath"
#define LISTEN_BACKLOG 50

#define handle_error(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

int main(void)
{
    int sfd, cfd;
    socklen_t peer_addr_size;
    struct sockaddr_un my_addr, peer_addr;

    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == -1)
        handle_error("socket");
    // bind locally through path
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sun_family = AF_UNIX;
    strncpy(my_addr.sun_path, MY_SOCK_PATH, sizeof(my_addr.sun_path) - 1);

    if (bind(sfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
        handle_error("bind");
    printf("Server bind() succeeded\n");

    if (listen(sfd, LISTEN_BACKLOG) == -1)
        handle_error("listen");
    printf("Server listen() succeeded\n");

    // handling incoming connections using accept
    peer_addr_size = sizeof(peer_addr);
    cfd = accept(sfd, (struct sockaddr *)&peer_addr, &peer_addr_size);
    if (cfd == -1)
        handle_error("accept");
    printf("Client connected!\n");

    // Dealing with socket errors
    // if (close(cfd) == -1)
    //     handle_error("close");

    // if (unlink(MY_SOCK_PATH) == -1)
    //     handle_error("unlink");
}