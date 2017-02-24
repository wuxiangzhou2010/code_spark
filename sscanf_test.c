#include<stdio.h>
/**
* brief: get try to use sscanf to get the input number
* usage: "./a.cout double float int"
*/
int main(int argc, char * argv[])
{
	double a;
	float b;
	int c;
	sscanf( argv[1],"%lf",&a);
	sscanf( argv[2],"%f",&b);
	sscanf( argv[3],"%d",&c);
	printf("a= %lf, b = %f, c= %d", a,b,c);
	return 0;
}