#include<stdio.h>


struct animal_struct {
        char dog;             /* 1 byte */
        unsigned long cat;    /* 4 bytes */
        unsigned short pig;   /* 2 bytes */
        char fox;             /* 1 byte */
};


struct animal_struct2 {
        unsigned long cat;    /* 4 bytes */
        unsigned short pig;   /* 2 bytes */
        char fox;             /* 1 byte */
        char dog;             /* 1 byte */
};

int main(int argc, char ** argv)
{
	struct animal_struct2 test;
	printf("0x%d\n", sizeof(test));
	return 0;
}
