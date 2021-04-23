#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue *next;
};
void insert(struct queue **front,struct queue **rear,int data);
void del(struct queue **front,struct queue **rear);
void display(struct queue **front,struct queue **rear);
int main()
{
	int ch,data;
	struct queue *front=NULL;
	struct queue *rear=NULL;
	printf("1.insert\n");
	printf("2.delete\n");
	printf("3.display\n");
	printf("4.exit");
	while (1)
	{
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&data);
				insert(&front,&rear,data);
				break;
			case 2:
				del(&front,&rear);
				break;
			case 3:
				display(&front,&rear);
				printf("\n");
				break;
			case 4:
				exit(1);
			default:
				printf("invalid choice\n");
		}
	}
	return 0;
}
void insert(struct queue **front,struct queue **rear,int data)
{
	struct queue *newnode,*temp;
	newnode=(struct queue*)malloc(sizeof(struct queue));
	newnode->data=data;
	newnode->next=NULL;
	if (*front==NULL && *rear==NULL)
	{
		*front=*rear=newnode;
	}
	else 
	{
		temp=*rear;
		temp->next=newnode;
		*rear=newnode;
	}
}
void display(struct queue **front ,struct queue **rear)
{
	struct queue *temp;
	temp=*front;
	if (*front==NULL && *rear==NULL)
	{
		printf("no data\n");
		
	}
	else 
	{
		while (temp !=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void del(struct queue **front,struct queue **rear)
{
	struct queue *temp;
	if (*front==NULL && *rear==NULL)
	{
		printf("underflow\n");
		return;
	}
	temp=*front;
	*front=temp->next;
	free(temp);
}
