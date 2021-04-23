#include<stdio.h>
#include<stdlib.h>
#define N 5
void insert(int *q,int *front,int *rear,int data);
int del(int *q,int *front,int *rear);
void display(int *q,int *front,int *rear);
int reverse(int *q,int *front,int *rear);
int main()
{
	int data,ch;
	int front=-1;
	int rear=-1;
	int *q=(int *)malloc(N*(sizeof(int)));
	while(1)
	{
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("5.reverse\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&data);
				insert(q,&front,&rear,data);
				break;
			case 2:
				del(q,&front,&rear);
				break;
			case 3:
				display(q,&front,&rear);
				printf("\n");
				break;
			case 4:
				exit(1);
				break;
			case 5:
				reverse(q,&front,&rear);
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void insert(int *q,int *front,int *rear,int data)
{
	if (*rear==N-1)
	{
		printf("overflow\n");
	}
	else if (*front==-1 && *rear==-1)
	{
		*front=0;
		*rear=0;
		q[*rear]=data;
	}
	else 
	{
		*rear=*rear+1;
		q[*rear]=data;
	}
}
int del(int *q,int *front,int *rear)
{
	if (*front==-1 &&  *rear==-1)
	{
		printf("underflow\n");
	}
	else if (*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else 
	{
		int ret=q[*front];
		*front=*front+1;
		return ret;
	}
}
void display(int *q,int *front,int *rear)
{
	if (*front==-1 && *rear==-1)
	{
		printf("no record\n");
	}
	else 
	{
		for (int i=*front;i<=*rear;i++)
		{
			printf("%d\t",q[i]);
		}
	}
}
int reverse(int *q,int *front,int *rear)
{
	int t=q[*front];
	if(*front<=*rear)
	{
		*front=*front+1;
		reverse(q,front,rear);
		insert(q,front,rear,t);
	}
}
