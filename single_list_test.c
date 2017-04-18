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
	return head;
}
/* traverse the list */
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

/* delete the list */
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
/** reverse  the list 
** for old list: need to get the list one bye one ()
** for the new list, the old list temp value should be stored after new list head 
*/
struct Node *reverse_list(struct Node *head)
{
	struct Node * temp_old = NULL;
	struct Node *old_last = NULL;
	struct Node *new = NULL;
	struct Node *temp_new = NULL;
	int first_flag = 1;
	printf("reverse list\n");

	old_last = head->next;
	while(old_last)
	{
		/* for old list */
		temp_old = old_last; 				/* get next value */
		old_last= old_last->next; 		/* old head move to next */	
		
		/* for new list */
		if(first_flag) 					/* if first, then new element's next is NULL */
		{
			new = (struct Node *)malloc(sizeof(struct Node)); /* get new list */
			new->next = temp_old;
			new->next->next = NULL;
			first_flag =0;
		}
		else
		{
			temp_new = new->next;
			new->next = temp_old;
			new->next->next = temp_new;
		}
	}
	return new;
}

int main(int argc, char const *argv[])
{
	struct  Node * list = NULL;
	list = create_list(); /* create single list */
	if(list)
	{
		print_list(list); /* traverse single list */
		list = reverse_list(list);
		print_list(list);
		free_list(list);  /* delete single list */
	}
	return 0;
}