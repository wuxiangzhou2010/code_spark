#include<stdio.h>
int main(int argc, char ** argv)
{
	unsigned char count = 0;
	unsigned char data = 222;

	 while(data!=0)
	 {
		 //不断的清楚data的二进制表示中最右边的1
		data &=(data-1);
		count++;
		printf("data = 0x%x, count == 0x%x\n", data, count);
	 }
	 return count;
}
