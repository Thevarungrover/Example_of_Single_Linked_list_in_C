#include<stdio.h>
#include<malloc.h>
#define ISEMPTY printf("\nEMPTY LIST :");
/* Node declaration */
struct node
{
	int value;
	struct node *next;
};

void insert_node_first();
void insert_node_last();
void insert_node_pos();
void delete_pos();
void search();
void display();

typedef struct node snode;
snode *newnode, *ptr, *prev, *temp;
snode *first = NULL,*last = NULL;

/* Main : contains menu */
int main()
{
	int ch;
	int ans ='Y';
	while(ans == 'Y' || ans =='y')
	{
		printf("\n------------------------------------\n");
		printf("\nOperations on singly linkesd lists\n");
		printf("\n------------------------------------\n");
		printf("\n1.Insert node at first");
		printf("\n2.Insert node at last");
		printf("\n3.Insert node at position");
		printf("\n4.Delete node from any position");
		printf("\n5.Search element in the linked list");
		printf("\n6.Display list from beginning to end ");
		printf("\n7.Exit");
		printf("\n`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\n...Inserting node at first...\n");
				insert_node_first();
				break;
			case 2:
				printf("\n...Inserting node at last...\n");
				insert_node_last();
				break;
			case 3:
				printf("\n...Inserting node at posion...\n");
				insert_node_pos();
				break;
			case 4:
				printf("\n...Deleting node from anuy position...\n");
				delete_pos();
				break;
			case 5:
				printf("\n...Searchimg element in the list...\n");
				search();
				break;
			case 6:
				printf("\n...Displaying list from beginning to end...\n");
				display();
				break;
			case 7:
				printf("\n...Exiting...\n");
				return 0;
				break;
			default:
			printf("\n...Invalid choice");
			break;					
		}
		printf("\nYOU WANT TO CONTINUE (Y/N)");
		scanf("%c",&ans);
	}
	return 0;
}

/* Creating node */
snode* create_node(int val)
{
	newnode = (snode*)malloc(sizeof(snode));
	if(newnode == NULL)
	{
		printf("\nMemory was not allocated");
		return 0;
	}
	else
	{
		newnode->value = val;
		newnode->next = NULL;
		return newnode;
	}
}

/* Inserting node at first */
void insert_node_first()
{
	int val;
	printf("\nEnter the value for the node :");
	scanf("%d",&val);
	newnode = create_node(val);
	if(first == last && first == NULL)
	{
		first = last = newnode;
		first->next = NULL;
		last->next = NULL;
	}
	else
	{
		temp = first;
		first = newnode;
		first->next = temp;
	}
	printf("\n---INSERTED---");
}

/* Inserting node at last */
void insert_node_last()
{
	int val;
	printf("\nEnter the value for the node :");
	scanf("%d",&val);
	newnode = create_node(val);
	if(first == last && last == NULL)
	{
		first = last = newnode;
		first->next = NULL;
		last->next = NULL;
	}
	else
	{
		last->next = newnode;
		last = newnode;
		last->next = temp;
	}
	printf("\n---INSERTED---");
}

/* Insertimg node at position */
void insert_node_pos()
{
	int pos, val, cnt=0,i;
	printf("\nEnter the value for the node :");
	scanf("%d",&val);
	printf("\nEnter the position :");
	scanF("%d",&pos);
	ptr = first;
	while(ptr != NULL)
	{
		ptr = ptr->next;
		cnt++;
	}
	if(pos == 1)
	{
		if(first == last && first == NULL)
		{
			first = last = newnode;
			first->next = NULL;
			last->next = NULL;
		}
		else
		{
			temp = first;
			first = newnode;
			first->next = temp;
		}
		printf("\nInserted");
	}
	else if(pos>1 && pos<=cnt)
	{
		ptr = first;
		for(i=0;i<pos;i++)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = newnode;
		newnode->next = ptr;
		printf("\n---Inserted---");
	}
	else
	{
		printf("Position is out of range");
	}
}

/* Delete node from specified position in a non empty list */
void delete_pos()
{
	int pos, cnt=0,i;
	if(first==NULL)
	{
		ISEMPTY;
		printf(" No node to delete\n");
	}
	else
	{
		printf("\nEnter the position of value to be deleted :");
		scanf("%d",&pos);
		ptr = first;
		if(pos == 1)
		{
			first = ptr->next;
			printf("\nElement deleted");
		}
		else
		{
			while(ptr != NULL)
			{
				ptr = ptr->next;
				cnt = cnt + 1;
			}
			if(pos>0 && pos<=cnt)
			{
				ptr = first;
				for(i=1;i< pos;i++)
				{
					prev = ptr;
					ptr = ptr->next;
				}
				prev->next = ptr->next;
			}
			else
			{
				printf("Position is out of range");
			}
			free(ptr);
			printf("\nElement deleted");
		}
	}
	
}

/* Searching an element in a non empty list */
void search()
{
	int flag = 0,key,pos = 0;
	if(first == NULL)
	{
		ISEMPTY;
		printf(":No nodes in the list\n");
	}
	else
	{
		printf("\nEnter the value to be searched :");
		scanf("%d",&key);
		for(ptr = first; ptr != NULL;ptr->next)
		{
			pos = pos +1;
			if(ptr->value ==key)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			printf("\nElement %d found at %d position",key,pos);
		}
		else
		{
			printf("\nElement %d not found in list\n",key);
		}
	}
}

/* Display non-empty list from beginning to end */
void display()
{
	if(first == NULL)
	{
		ISEMPTY;
		printf(": No nodes in the list to display");
	}
	else
	{
		for(ptr = first;ptr != NULL;ptr = ptr->next)
		{
			printf("%d\t",ptr->value);
		}
	}
}

/* Exit */

