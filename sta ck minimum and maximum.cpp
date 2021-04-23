#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;


void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("stack overflow\n");
    }
    else
    {

        t->data = x;
        t->next = top;
        top = t;
    }
}

void pop()
{

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }

    else
    {
        int x = -1;
        struct node *t = top;
        top = top->next;
        x = t->data;
        t->next = NULL;
        free(t);
        printf("Deleted element is %d\n", x);
    }
}


void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *p = top;
        while (p)
        {
            printf("Data inside stack is %d\n", p->data);
            p = p->next;
        }
    }
}

int max()
{
    struct node *temp=top;
    int x=INT_MIN;
    while(temp)
    {
        if(temp->data>x)
        x=temp->data;
        temp=temp->next;
    }
    return x;
}
int min()
{
    struct node *temp=top;
    int x=INT_MAX;
    while(temp)
    {
        if(temp->data<x)
        x=temp->data;
        temp=temp->next;
    }
    return x;
}
int main()
{

    int num, item, choice;
    
    while (1)
    {
        printf("What operation do you want me to perform for you:\n1.push\n2.pop\n3.display\n4.exit\n5.Maximum Element\n6.Minunum Element\n");
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the number of nodes\n");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("Enter the element %d\n",i+1);
                scanf("%d", &item);
                push(item);
            }
            break;
        }

        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("End of the program.\n");
            exit(0);
            case 5:
            printf("Maximum element is %d.\n",max());
            break;
             case 6:
            printf("Minimum element is %d.\n",min());
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
