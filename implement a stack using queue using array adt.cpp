/*Roll no-1905539
Name-Manraj Singh
*/
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
struct queue
{
    int f,r ;
    int arr[MAX] ;
};
void insert(struct queue *s,int x)
{
    struct queue *t=s;
    if(t->r==MAX-1)
    {
        printf("overflow\n") ;
        return ;
    }
    if(t->f==-1&&t->r==-1)
    {
        t->f=0 ;
    }
    t->r++ ;
    t->arr[t->r]=x ;
}
int del(struct queue *s)
{
    struct queue *t=s;
    if(t->f==-1)
    {
        printf("underflow\n") ;
        return -1;
    }
    if(t->f==t->r)
    {
        t->f=-1 ;
        t->r=-1 ;
    }
    int x=s->arr[s->f] ;
    (s->f)++ ;
    return x ;
}
int pop(struct queue *s)
{
int z ;
    if(s->f==s->r)
    {
        int x=del(s) ;
        return x ;
    }
    else
    {
        z=del(s) ;
        pop(s) ;
        insert(s,z) ;

    }

    return z;
}
void display(struct queue *s,struct queue *m)
{
    while(s->f<=s->r)
    {
        printf("%d ",s->arr[s->f]) ;
        insert(m,s->arr[s->f]) ;
        s->f++ ;

    }
    printf("\ndone\n") ;
    while(m->f<=m->r)
    {
        insert(s,m->arr[m->f]) ;
        m->f++ ;

    }
}
void reverse(struct queue *s)
{
    int t=s->arr[s->f] ;
    if(s->f<=s->r)
    {
        s->f++ ;
        reverse(s) ;
        insert(s,t);
    }
}

int main(void)
{
    struct  queue *s ;
    s=(struct queue*)malloc(sizeof(struct queue)) ;
    s->r=-1 ;
    s->f=-1 ;
    struct  queue *m ;
    m=(struct queue*)malloc(sizeof(struct queue)) ;
    m->r=-1 ;
    m->f=-1 ;

    while(1)
    {
        int z ;

        printf("1 to insert\n2 to delete\n3 to display\n0 to quit\n") ;
        scanf("%d",&z) ;

        switch(z)
        {
        case 1:
            {
                printf("\nEntervalue\n") ;
                int x ;
                scanf("%d",&x) ;
                insert(s,x)   ;
                break ;
            }
        case 2:
            {
                int k= pop(s) ;
                reverse(s) ;
                break ;
            }
        case 3:
            {
                display(s,m);
                break ;
            }
        }
        if(z==0)
            break ;
    }


    return 0 ;
}
