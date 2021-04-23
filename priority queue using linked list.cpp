#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
	int data;
	int pr;
	struct node *next;
};
void insert(struct node **start,int data,int priority);
void del(struct node **start);
void display(struct node **start);
int main()
{
	struct node *start=NULL;
	int ch,data,priority;
	while (1)
	{
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				printf("enter the priority\n");
				scanf("%d",&priority);
				insert(&start,data,priority);
				break;
			case 2:
				del(&start);
				break;
			case 3:
				display(&start);
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void insert(struct node **start,int data,int priority)
{
	struct node *newnode,*t1,*t2;
	t1=t2=*start;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->pr=priority;
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;
	}
	else 
	{
		t1=t2=*start;
		while (t1->pr>=priority && t1!=NULL)
		{
			t2=t1;
			t1=t1->next;
		}
		t2->next=newnode;
		newnode->next=t1;
	}
}
void del(struct node **start)
{
	if (*start==NULL)
	{
		printf("underflow\n");
	}
	struct node *temp=*start;
	*start=temp->next;
	free(temp);
}
void display(struct node **start)
{
	struct node *temp=*start;
	while (temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
