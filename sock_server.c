#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htons(INADDR_ANY);
	server.sin_port = htons(2222);

	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd)
		printf("create socket successfully, 0x%x\n", sd);
	if(bind(sd, (struct sockaddr*)&server, sizeof(server)) < 0)
	{

		printf("Bind failed\n");
		close(sd);
		return -1;
	}
	printf("Bind successfully\n");
while(1)
{
	if(listen(sd, 12))
	{
		printf("Listen failed\n");
		close(sd);
		return -2;
	}

	int client_sock = socket(AF_INET, SOCK_STREAM, 0);
	socklen_t  socklen= sizeof(server);
	client_sock = accept(sd,(struct sockaddr*)&server, &socklen);
	if(client_sock<0)
	{
		printf("Accept failed\n");
	}
	printf("Server is listening\n");
}
	return 0;
}