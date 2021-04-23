#include<stdio.h>
#include<stdlib.h>
#define N 5
void insertfront(int *arr,int *front,int *rear,int data);
void insertrear(int *arr,int *front,int *rear,int data);
void deletefront(int *arr,int *front,int *rear);
void deleterear(int *arr,int *front,int *rear);
void display(int *arr,int *front,int *rear);
int main()
{
	int ch,data;
	int *ptr=(int *)malloc (N * (sizeof(int)));
	int front=-1;
	int rear=-1;
	while (1)
	{
		printf("1.insert front\n");
		printf("2.insert rear\n");
		printf("3.delete front\n");
		printf("4.delete rear\n");
		printf("5.display\n");
		printf("6.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				insertfront(ptr,&front,&rear,data);
				break;
			case 2:
				printf("enter the data\n");
				scanf("%d",&data);
				insertrear(ptr,&front,&rear,data);
				break;
			case 3:
				deletefront(ptr,&front,&rear);
				break;
			case 4:
				deleterear(ptr,&front,&rear);
				break;
			case 5:
				display(ptr,&front,&rear);
				printf("\n");
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void insertfront(int *arr,int *front,int *rear,int data)
{
	if ((*front==0 && *rear==N-1)||*front==*rear+1 )
	{
		printf("overflow\n");
	}
	else if (*front==-1 && *rear==-1) 
	{
		*front=0;
		*rear=0;
		arr[*front]=data;
	}
	else if (*front==0)
	{
		*front=N-1;
		arr[*front]=data;
	}
	else 
	{
		*front=*front-1;
		arr[*front]=data;
	}
	
}
void insertrear(int *arr,int *front,int *rear,int data)
{
	if ((*front==0 && *rear==N-1)||*front==*rear+1 )
	{
		printf("overflow\n");
	}
	else if (*front==-1 && *rear==-1) 
	{
		*front=0;
		*rear=0;
		arr[*rear]=data;
	}
	else if (*rear==N-1)
	{
		*rear=0;
		arr[*rear]=data;
	}
	else 
	{
		*rear=*rear+1;
		arr[*rear]=data;
	}
}
void display(int *arr,int *front,int *rear)
{
	int i=*front;
	while (i!=*rear)
	{
		printf("%d\t",arr[i]);
		i=(i+1)%N;
	}
	printf("%d\t",arr[*rear]);
}
void deletefront(int *arr,int *front,int *rear)
{
	if (*front==-1 && *rear==-1)
	{
		printf("queue is empty\n");
	}
	else if (*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else if (*front==N-1)
	{
		*front=0;
	}
	else 
	{
		*front=*front+1;
	}
}
void deleterear(int *arr,int *front,int *rear)
{
	if (*front==-1 && *rear==-1)
	{
		printf("queue is empty\n");
	}
	else if (*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else if (*rear==N-1)
	{
		*rear=0;
	}
	else 
	{
		*rear=*rear-1;
	}
}
