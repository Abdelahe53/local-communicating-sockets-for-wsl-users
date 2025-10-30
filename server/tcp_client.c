#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>


int main()
{
	int socketFD = socket(AF_UNIX, SOCK_STREAM, 0); //domain, type, protocol.

	struct sockaddr_in address;
	address.sin_familly = AF_UNIX;
	address.sin_port = 2000;
	address.sin_addr.s_addr;
	inet_pton

	connect(socketFD, &address, sizeof address);




	return 0;
}
