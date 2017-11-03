/*
 *
 * It always padding to the largest member in the struct
 * say short, then size is n * sizeof(short), 
 * say long, then size id n * sizeof(long)
 * */


#include<stdio.h>
#include <stddef.h>

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
struct animal_struct3 {
        long long cat;    		/* 8 bytes */
        unsigned short pig;   	/* 2 bytes */
        char fox;             	/* 1 byte */
        long long dog;          /* 8 byte */
};

/* using nm -S a.out to identify */
struct animal_struct test1={0}; /*  in the BSS area*/
struct animal_struct test2={1}; /*  in the data area*/

int main(int argc, char ** argv)
{
	struct animal_struct2 test; /* in the stack frame */

	// printf("0x%d\n", offsetof(struct animal_struct3,pig));
	printf("0x%d\n", sizeof(struct animal_struct2));
	return 0;
}
