#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#define BUFFER_SIZE (1024)
char buffer[BUFFER_SIZE];

char *filename = "test.txt";
char *filename2 = "test2.txt";
int length;
int main(int argc, char *argv[])
{
	int fd = open(filename, O_RDWR);
	int fd2 = open(filename2, O_RDWR|O_TRUNC);
	if(fd) /* file open ok */
	{
		while(length = read(fd, (void*)buffer, BUFFER_SIZE)) /* get all content, 12 byte each time */
		{
			printf("%s",(char *)buffer );
			write(fd2, (void*)buffer, length == BUFFER_SIZE?BUFFER_SIZE:length);
			bzero(buffer, BUFFER_SIZE); /* clear */
		}
		close(fd);
		close(fd2);
	}
	else
	{
		printf("Open file: %s failed\n", filename);
	}
	
	return 0;
}