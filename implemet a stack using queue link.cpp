#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
};
struct queue
{
struct node *rear;
struct node *front;
}q1,q2;
void initial(struct queue *);
void add(struct queue *,int);
int del(struct queue *);
void dis(struct queue *);
void push(int);
void pop();
int main()
{
initial(&q1);
initial(&q2);
push(5);
push(6);
push(7);
push(700);
pop();
pop();
printf("\nelements now are:\n");
dis(&q1);
return 0;
}
void initial(struct queue *q)
{
q->front=NULL;
q->rear=NULL;
}

void add(struct queue *q,int n){
struct node *tmp;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->data=n;
tmp->next=NULL;
if(q->front==NULL)
{
q->rear=tmp;
q->front=tmp;
return;
}
q->rear->next=tmp;
q->rear=tmp;
}

int del(struct queue *q)
{
struct node *tmp;
int itm;
if(q->front==NULL)
{
printf("\nqueue is empty");
return 0;
}

tmp=q->front;
itm=tmp->data;
q->front=tmp->next;
free(tmp);
return itm;
}
void dis(struct queue *q)
{
struct node *tmp;
tmp=q->front;
while((tmp)!=NULL)
{
printf("\n%d",(tmp->data));
tmp=tmp->next;
}
printf("\n");
}
void push(int val)
{
struct queue tmp;
int j;
add(&q2,val);
while(((&q1)->front)!=NULL)
{
j=del(&q1);
add(&q2,j);
}
tmp=q1; //swap q1 and q2
q1=q2;
q2=tmp;
printf("\nelements after pushing are:\n");
dis(&q1);
}
void pop()
{
printf("\n element deleted is %d",del(&q1));
}
