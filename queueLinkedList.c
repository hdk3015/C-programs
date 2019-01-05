#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *rear =NULL, *front = NULL;

void insert(int item);
int delete();
int peek();
int isEmpty();
void display();

int main()
{
	int item, ch;
	system("cls");
	while(1)
	{
		printf("\n\nQueue Implementation using array --> ");
		printf("\n1.Insertion");
		printf("\n2.Deletion");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");

		printf("\nEnter Your choice--> ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter Item to insert in queue -->  ");
					scanf("%d",&item);
					insert(item);
					printf("\n%d Item inserted in queue",item);
					break;
			case 2: item = delete();
					if(item == -1)
						printf("\nQueue Empty");
					else
					{
						printf("\n%d Item deleted from queue",item);
					}
					break;
			case 3: item = peek();
					if(item == -1)
						printf("\nQueue Empty");
					else
					{
						printf("\n%d Item in top queue",item);
					}
					break;
			case 4: display();
					break;
			case 5: exit(0);
					break;
			default: printf("\nPlease Enter correct option");
					break;
		}

		}
}

void insert(int item)	
{	/*Insertion happens in the end of the list*/
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\n**Queue Overflow**");
		exit(-1);
	}
	temp->data = item;
	temp->link = NULL;
	if(front == NULL)
	{
		front = temp;
	}
	else
	{
		rear->link = temp;
	}
	rear = temp;
}
int delete()
{
	int item;
	struct node *temp;
	if(isEmpty())
	{
		return -1;
	}
	temp = front;
	item = temp->data;
	front = front->link;
	free(temp);
	return item;
}
int peek()
{
	if(isEmpty())
	{
		return -1;
	}
	return (front->data);
}

int isEmpty()
{
	if(front == NULL)
	{
		return 1;
	}
	return 0;
}
void display()
{
	struct node *p;
	if(isEmpty())
	{
		printf("\nList is empty");
		return;
	}
	p = front;
	printf("\nQueue Item --> \n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->link;
	}
	printf("\n");
}