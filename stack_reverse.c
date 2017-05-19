/*
* transfer "I am a teacher." to "teacher. a am I"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *st[20];
int stack_size;
void stack_init(void)
{
	stack_size = 0;
}
char * stack_pop(void)
{
	stack_size--;
	if(stack_size == -1)
		return NULL;

	return st[stack_size];
}
void stack_push( char *s)
{
	st[stack_size] = s;
	stack_size++;

}

int main(int argc, char *argv[])
{
	char *s = "I am a teacher.";
	char *start = s;
	char *end = s;
	char *temp = s;
	stack_init();
	while(*temp != '\0')
	{
		if(*temp == ' ')
		{
			end = temp;
			char * node = (char *)malloc(10);
			strncpy(node, start, end - start);
			stack_push(node);
			start = end +1;
		}
		temp++;
	}
	end = temp;
	char * node = (char *)malloc(10);
	strncpy(node, start, end - start);
	stack_push(node);

	char *s2 = NULL;
	int flag = 0;
	while((s2 = stack_pop()))
	{
		(flag == 0)?flag = 1:printf(" ");
		printf("%s",s2);
		free(s2);//do not forget to free

	}
	printf("\n");

}