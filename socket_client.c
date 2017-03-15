#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>			/* for close() */

int main(int argc, char *argv[])
{
	/* client addr */
	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = INADDR_ANY;
	client_addr.sin_port = htons(0);
	
	/* client socket */
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(client_socket < 0)
	{
		printf("create socket failed\n");
		return -1;
	}
	/* client socket bind to client addr */
	if(bind(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0)
	{
		printf("Bind failed\n");
		close(client_socket);
		return -2;
	}
	/* server addr */
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(2222);
		
	socklen_t len2 = sizeof(server_addr);
	/* client connect to server */
	if(connect(client_socket, (struct sockaddr *)&server_addr, len2)) /* return 0 if successful */
	{	
		printf("Connect failed\n");
		close(client_socket);
		return -3;
	}		

	return 0;
}