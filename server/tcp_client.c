#include <sys/socket.h>

int main()
{
	int	socket_door;
	int	bind_name;

	//socket
	socket_door = socket(AF_UNIX, SOCK_STREAM, 0);

	//bind
	bind_name = bind()
}
