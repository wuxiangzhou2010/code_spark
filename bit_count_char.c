#include<stdio.h>
int main(int argc, char ** argv)
{
	unsigned char count = 0;
	unsigned char temp = 222;
	
	while(temp)
	{
		printf("temp  = 0x%x\n", temp);
		if(temp & 1)
			count++;
		temp >>=1;
	}
	printf("count  = 0x%x\n", count);
	return count;
}