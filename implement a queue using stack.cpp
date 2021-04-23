#include<stdio.h>
#include<stdlib.h>
#define N 5
int count=0;
void enqueue(int *s,int *top1,int *top2,int data);
void dequeue(int *s1,int *s2,int *top1,int *top2);
void push(int *s,int *top,int data);
int pop(int *s,int *top);
void display(int *s,int *top);
int main()
{
	int top1=-1,top2=-1;
	int ch,data;
	int *s1=(int *)malloc(N*(sizeof(int)));
	int *s2=(int *)malloc(N*(sizeof(int)));
	while (1)
	{
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.display\n");
		printf("4.exit\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				enqueue(s1,&top1,&top2,data);
				break;
			case 2:
				dequeue(s1,s2,&top1,&top2);
				break;
			case 3:
				display(s1,&top1);
				break;
			case 4:
				exit(1);
			default:
				printf("wrong choice\n");
		}
		
	}
	return 0;
}
void push(int *s,int *top,int data)
{
	if (*top==N-1)
	{
		printf("overflow\n");
	}
	else 
	{
		*top=*top+1;
		s[*top]=data;
	}
}
int pop(int *s,int *top)
{
	int ret;
	ret=s[*top];
	*top=*top-1;
	return ret;
}
void enqueue(int *s,int *top1,int *top2,int data)
{
	push(s,top1,data);
	count++;
}
void dequeue(int *s1,int *s2,int *top1,int *top2)
{
	if (*top1==-1 && *top2==-1)
	{
		printf("underflow\n");
	}
	else 
	{
		int i,a,b;
		for (i=0;i<count;i++)
		{
			a=pop(s1,top1);
			push(s2,top2,a);
		}
		b=pop(s2,top2);
		count--;
		for (a=0;a<count;a++)
		{
			b=pop(s2,top2);
			push(s1,top1,b);
		}
	}
}
void display(int *s,int *top)
{
	int i;
	for (i=0;i<=*top;i++)
	
	{
		printf("%d\t",s[i]);
	}
	printf("\n");
}
