#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	struct sockaddr_in client_sock;
	client_sock.sin_family = AF_INET;
	client_sock.sin_addr.s_addr = htons(INADDR_ANY);
\	client_sock.sin_port = htons(0);

	int client_sd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_sd)
		printf("create socket successfully, 0x%x\n", client_sd);
	if(bind(client_sd, (struct sockaddr*)&client_sock, sizeof(client_sock)) < 0)
	{

		printf("Bind failed\n");
		close(client_sd);
		return -1;
	}
	printf("Bind successfully\n");
	
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	// server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	server_addr.sin_addr.s_addr = inet_addr("10.25.15.107");
	server_addr.sin_port = htons(2222);
		
	socklen_t len2 = sizeof(server_addr);
	if(connect(client_sd, (struct sockaddr *)&server_addr, len2))
	{
		printf("Connect failed\n");
	}		

	return 0;
}