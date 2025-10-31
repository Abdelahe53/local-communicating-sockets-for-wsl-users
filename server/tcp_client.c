#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h> 

int main()
{
	//create socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	int connection_status = connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address));
	//check for error connection
	if (connection_status == -1)
	{
		printf("ydak feh");
	}
	//recieve data from the server
	char server_response[256];
	recv(sockfd, &server_response, sizeof(server_response), 0);

	//print out the server's response
	printf("the server sent the data: %s\n", server_response);

	//and then close the socket
	close(sockfd);
	return 0;
}

