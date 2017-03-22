#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* next;
};

struct Node* create_list(void)
{
	int break_flag = 0; /* if input value is less than 0, then need to break*/
	int first_flg = 1; /* head need to deal with seperately */
	struct Node *head = NULL; /* head, changed only the  first time*/
	struct Node *temp = NULL; /* malloced temp value */
	struct Node *pre = NULL;  /* save the last list item */

	while(1)
	{
		/* malloc a temp node */
		temp = (struct Node *)malloc(sizeof(struct Node));
		if(temp)
		{
			puts("Please input node value:");
			scanf("%d",&temp->value);  /* get input value */
			if(temp->value <0) /* if less than 0 then break */
			{
				break_flag = 1; /* break flag */
				free(temp);
				break;
			}			
			if(first_flg) /* deal with head */
			{
				head = (struct Node *)malloc(sizeof(struct Node));
				head->next  =  temp; 
				pre = head->next;	
				first_flg = 0;
			}
			else
			{
				pre->next = temp;
				temp->next = NULL;
				pre = temp;
			}
		}
		else
		{
			printf("Malloc failed\n"); 
			free(head); /*if malloc failed, should free the already allocated memory*/

		}
		if(break_flag)
			break;
	}
	if(head)
		return head;
	else
		return NULL;

}
void print_list(struct Node * list)
{
	struct Node * temp =  list;
	if(temp)
	{
		const 	struct Node * temp =  list->next;
		while(temp)
		{
			printf("%d\n",temp->value);
			temp = temp->next;
		}
	}

}

void free_list(struct Node *  head)
{
	struct Node * temp=NULL;
	while(head->next)
	{
		temp = head->next; /* node to free */
		head->next= head->next->next; /* head move to next */
		printf("free %d\n", temp->value); /* free the */
		free(temp);
	}
}

int main(int argc, char const *argv[])
{
	struct  Node * list = NULL;
	list = create_list();
	if(list)
	{
		print_list(list);
		free_list(list);
	}
	return 0;
}