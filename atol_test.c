#include<stdlib.h>
#include<stdio.h>
/*
* brief: use atol() to get the input number
* usage: "./a.out (number in 0~255)"
*/
int main(int argc, char ** argv)
{
	unsigned char temp = atol(argv[1]);

	unsigned char count = 0;	
	while(temp)
	{
		if(temp & 1)
			count++;
		temp >>=1;
		printf("temp = 0x%x\n",temp);
	}
	printf("count = 0x%x\n",count);
	sleep(2); 
	return count;
}
