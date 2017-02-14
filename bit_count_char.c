#include<stdio.h>

/*
http://blog.chinaunix.net/uid-26758209-id-3106310.html
1. 移位
2. 移除末位的1
3. 位段相加
*/
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