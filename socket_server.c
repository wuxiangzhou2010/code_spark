#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>			/* for close() */
#include <fcntl.h> 			/* for open */


int main(int argc, char *argv[])
{
	/* server addr  */
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(2222);

	/* server socket*/
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0)
	{
		printf("create socket failed\n");
		return -1;
	}
	/* bind server addr to server socket */
	if(bind(sd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("Bind failed\n");
		close(sd);
		return -2;
	}
	printf("Bind successfully\n");
	/* listen */
	if(listen(sd, 12))
	{
		printf("Listen failed\n");
		close(sd);
		return -3;
	}
	printf("Server is listening\n");

	/* accept */
	int accept_socket = socket(AF_INET, SOCK_STREAM, 0); /* accept will return a socket fd */
	socklen_t  socklen= sizeof(server_addr);
	while(1)
	{
		accept_socket = accept(sd,(struct sockaddr*)&server_addr, &socklen);
		if(accept_socket < 0)
		{
			printf("Accept failed\n");
			break;
		}
	}
	
	close(sd);
	return 0;
}