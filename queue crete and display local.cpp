#include<stdio.h>
#include<stdlib.h>
void *insert(int arr[],int size,int *front,int *rear,int data);
void *display(int arr[],int arr1[],int *front,int *rear);
int *del(int arr[],int *front,int *rear);
int main()
{
	int count=0;
	int info;
	int front=-1;
	int rear=-1;
	int size=5,ch=1;
//	printf("enter the size of the array\n");
//	scanf("%d",&size);
	int *ptr=(int *)malloc(size*(sizeof(int)));
	int *ptr1=(int *)malloc(size*(sizeof(int)));
	while (ch==1)
	{
		count++;
		printf("enter the data to be entered\n");
		scanf("%d",&info);
		insert(ptr,size,&front,&rear,info);
		printf("do you want to enter more\n");
		scanf("%d",&ch);
	}
	display(ptr,ptr1,&front,&rear);
}
void *insert(int arr[],int size,int *front,int *rear,int data)
{
	
	if (*rear==size-1)
	{
		printf("overflow\n");
	}
	else if (*front==-1 && *rear==-1)
	{
		*front=0;
		*rear=0;
		arr[*rear]=data;
	}
	else 
	{
		*rear=*rear+1;
		arr[*rear]=data;
	}
}
void *display(int arr[],int arr1[],int *front,int *rear)
{
	int i;
	int t1,t2;
	for (i=*front;i<=*rear;i++)
	{
		t1=del(arr,&front,&rear);
		printf("%d\t",t1);
		insert(arr1,5,&front,&rear,t1);
	}
	for (i=*front;i<=*rear;i++)
	{
		t2=del(arr1,&front,&rear);
		insert(arr,5,&front,&rear,t2);
	}
	
}
int *del(int arr[],int *front,int *rear)
{
	if (*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else 
	{
		int ret=arr[*front];
		*front=*front+1;
		return ret;
	}
}
