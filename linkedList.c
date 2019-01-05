#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
/*Function declarations*/
struct node *createList(struct node *start);
struct node *add_at_begin(struct node *start, int item);
struct node *add_at_end(struct node *start, int item);
struct node *add_after_node(struct node *start, int item, int pos);
struct node *add_before_node(struct node *start, int item, int pos);
struct node *add_at_pos(struct node *start, int item, int pos);
struct node *deleteNode(struct node *start, int item);
struct node *reverse(struct node *start);
void displayList(struct node *start);
int countList(struct node *start);
int searchNode(struct node *start, int item);

/*Main Function*/
int main()
{
	struct node *start = NULL;
	int ch,item,pos;
	system("cls");
	while(1)
	{
		printf("\n\n\n-- Linked List --\n\n");
		printf("\n1.Create List");
		printf("\n2.Display");
		printf("\n3.Count");
		printf("\n4.Add to empty list / Add at begining");
		printf("\n5.Add at end");
		printf("\n6.Add after a node");
		printf("\n7.Add at before a node");
		printf("\n8.Add at a position");
		printf("\n9.Delete");
		printf("\n10.Reverse");
		printf("\n11.Search");
		printf("\n12.Quit");
		printf("\n\nEnter your option--> ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: start = createList(start);
					printf("\nList Created");
					break;

			case 2: displayList(start);
					break;

			case 3: item = countList(start);
					printf("\nList Count --> %d",item);
					break;

			case 4: printf("\nEnter item to insert in the beginning of the list --> ");
					scanf("%d",&item);
					start = add_at_begin(start,item);
					break;

			case 5: printf("\nEnter item to insert in the end of the list --> ");
					scanf("%d",&item);
					start = add_at_end(start, item);
					break;

			case 6: printf("\nEnter item to insert in the list --> ");
					scanf("%d",&item);
					printf("\nEnter position data to insert after --> ");
					scanf("%d",&pos);
					start = add_after_node(start,item,pos);
					break;
			case 7: printf("\nEnter item to insert in the list --> ");
					scanf("%d",&item);
					printf("\nEnter position data to insert before --> ");
					scanf("%d",&pos);
					start = add_before_node(start,item,pos);
					break;
			case 8: printf("\nEnter item to insert in the list --> ");
					scanf("%d",&item);
					printf("\nEnter positon --> ");
					scanf("%d",&pos);
					start = add_at_pos(start,item,pos);
					break;
			case 9: printf("\nEnter item to be deleted --> ");
					scanf("%d",&item);
					start = deleteNode(start, item);
					break;
			case 10: start = reverse(start);
					printf("\nList reversed\n");
					displayList(start);
					break;
			case 11: printf("\nEnter item to be searched --> ");
					 scanf("%d",&item);
					 pos = searchNode(start,item);
					 if(pos == -1)
					 {
						 printf("\nItem %d not present in list", item);
					 }
					 else
					 printf("\nItem %d present in %d position",item,pos+1);
					 break;
			case 12 : exit(1);
			default : printf("\nEnter correct option");
					  break;
		}
	}
}

struct node *createList(struct node *start)
{
	int n,i = 1,item;
	printf("\nEnter Number of nodes --> ");
	scanf("%d",&n);
	if(n==0)
	return start;
	printf("\nEnter item %d --> ", i);
	scanf("%d",&item);
	start = add_at_begin(start,item);
	for(i=2;i<=n;i++)
	{
		printf("\nEnter item %d --> ", i);
		scanf("%d",&item);
		start = add_at_end(start, item);
	}
	return start;
	}

void displayList(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nList is Empty");
		return;
	}
	p = start;
	printf("\nList --> \n");
	while(p!=NULL)
{
	printf("%d ",p->data);
	p = p->link;
}
printf("\n");
}

struct node * reverse(struct node *start)
{
	struct node *prev,*ptr,*next;
	prev = NULL;
	ptr = start;
	while(ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

int countList(struct node *start)
{
	struct node *p;
	int cnt = 0;

	p = start;
	while(p!=NULL)
	{
		p = p->link;
		cnt++;
	}
	return cnt;
}
int searchNode(struct node *start, int item)
{
	struct node *p;
	int pos;
	p = start;
	while(p!=NULL)
	{
		if(p->data == item)
		{
			return pos;
		}
		p = p->link;
		pos++;
	}
	return -1;
}
struct node *add_at_begin(struct node *start, int item)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->link = start;
	start = temp;
	return start;
}
struct node *add_at_end(struct node *start, int item)
{
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	p = start;
	while(p->link!=NULL)
	{
		p = p->link;
	}
	p->link = temp;
	temp->link = NULL;
	return start;
}
struct node *add_after_node(struct node *start, int item, int pos)
{
	struct node *p, *temp;
	p = start;
	while(p!=NULL)
	{
		if(p->data == pos)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = item;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("\n%d item not present in the list!",pos);
	return start;
}
struct node *add_before_node(struct node *start, int item, int pos)
{
	struct node *temp, *p;
	if(start == NULL)
	{ 
		printf("\nList is Empty");
		return start;
	}
	if(start->data == pos)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = item;
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	while(p->link != NULL)
	{
		if(p->link->data == pos)
		{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = item;
		temp->link = p->link;
		p->link = temp;
		return start;
		}
		p = p->link;
	}
	printf("\n%d item not present in the list",pos);
	return start;
}
struct node *add_at_pos(struct node *start, int item, int pos)
{
	struct node *p, *temp;
	int i;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	if(pos==1)
	{
			
			temp->link = start;
			start = temp;
			return start;

	}
	p = start;
	for(i=0;i<pos-1 && p!=NULL;i++)
	{
		p = p->link;
	}
	if(p==NULL)
	{
		printf("\nThere are less than %d elements ",pos);
	}
	else{
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}
struct node *deleteNode(struct node *start, int item)
{
	struct node *temp, *p;
	if(start == NULL)
	{
		printf("\nList is empty");
		return start;
	}
	if(start->data == item)
	{
			temp = start;
			start = start->link;
			free(temp);
			return start;
	}
p = start;
while(p->link != NULL)
{
	if(p->link->data == item)
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
		return start;
	}
	p = p->link;
}
printf("\n%d item not in list ",item);
	return start;
}
