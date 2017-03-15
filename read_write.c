/**
** usage: 	gcc -g -o read_write read_write.c -Wall
** 			./read_write
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>


#define BUFFER_SIZE (1024)
char buffer[BUFFER_SIZE];

char *filename = "test.txt";
char *filename2 = "test2.txt";
int length;
int main(int argc, char *argv[])
{
	int fd = open(filename, O_RDWR);  /* open for read and write*/
	int fd2 = open(filename2, O_RDWR|O_CREAT); /* open for read and write, if not exist create it*/
	if(fd2 < 0)
	{
		printf("open %s Failed\n", filename2);
	}
	if(fd > 0) /* file open ok */
	{
		/* On success, the number of bytes read is returned,  On error, -1 is returned */
		while((length = read(fd, (void*)buffer, BUFFER_SIZE))) 
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