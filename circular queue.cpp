#include<stdio.h>
#include<stdlib.h>
# define N 5
struct queue{
	int front;
	int rear;
	int q[N];
};
void insert(struct queue *s,int data);
int del(struct queue *s);
void display(struct queue *s);
int main()
{
	int ch,data;
	struct queue *s=(struct queue*)malloc(sizeof(struct queue));
	s->front=-1;
	s->rear=-1;
	printf("1.insert\n");
	printf("2.delete\n");
	printf("3.display\n");
	printf("4.exit");
	while (1)
	{
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				insert(s,data);
				break;
			case 2:
				del(s);
				break;
			case 3:
				display(s);
				break;
			case 4:
				exit(1);
			default:
				printf("wrong choice\n");
		}
	}
}
void insert(struct queue *s,int data)
{
	if (s->front==-1 && s->rear==-1)
	{
		s->front=0;
		s->rear=0;
		s->q[s->rear]=data;
	}
	else if (((s->rear + 1)%	N)==s->front )
	{
		printf("overflow\n");
	}
	else 
	{
		s->rear=(s->rear +1)%N;
		s->q[s->rear]=data;
	}
}
int  del(struct queue *s)
{
	if (s->front==-1 && s->rear==-1)
	{
		printf("underflow\n");
	}
	else if (s->front==s->rear)
	{
		s->front=-1;
		s->rear=-1;
	}
	else 
	{
		int ret=s->q[s->front];
		s->front=(s->front+1)%N;
	}
}
void display(struct queue *s)
{
	if (s->front==-1 && s->rear==-1)
	{
		printf("empty\n");
	}
	else 
	{
		while (s->front!=s->rear)
		{
			printf("%d\t",s->q[s->front]);
			s->front=(s->front+1)%N;
		}
		printf("%d\t",s->q[s->rear]);
	}
	printf("\n");
}
