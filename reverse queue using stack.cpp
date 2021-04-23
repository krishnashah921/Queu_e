#include <stdio.h>
#include <stdlib.h>
 
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();
 
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
 
int main()
{
    int ch;
 
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    create();
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}
 
//Function to create a queue/
void create()
{
    top1 = top2 = -1;
}
 
//Function to push the element on to the stack/
void push1(int data)
{
    st1[++top1] = data;
}
 
//Function to pop the element from the stack/
int pop1()
{
    return(st1[top1--]);
}
 
//Function to push an element on to stack/
void push2(int data)
{
    st2[++top2] = data;
}
 
//Function to pop an element from th stack/
 
int pop2()
{
    return(st2[top2--]);
}
 
//Function to add an element into the queue using stack/
void enqueue()
{
    int data, i;
 
    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);
    count++;
}
 
//Function to delete an element from the queue using stack/
 
void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}
 
//Function to display the elements in the stack/
 
void display()
{
    int i;
 
    for (i = 0;i <= top1;i++)
    {
        printf(" %d ", st1[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
 
/* Queue structure */
 
#define QUEUE_EMPTY_MAGIC 0xdeadbeef
typedef struct _queue_t {
    int *arr;
    int rear, front, count, max;
} queue_t;
 
/* Queue operation function prototypes */
queue_t *queue_allocate(int n);
void queue_insert(queue_t * q, int v);
int queue_remove(queue_t * q);
int queue_count(queue_t * q);
int queue_is_empty(queue_t * q);
void stack_push(queue_t * q, int v) {
    queue_insert(q, v);
}
 
int stack_pop(queue_t * q) {
    int i, n = queue_count(q);
    int removed_element;
 
    for (i = 0; i < (n - 1); i++) {
        removed_element = queue_remove(q);
        queue_insert(q, removed_element);
        /* same as below */
        //queue_insert (q, queue_remove (q))
    }
    removed_element = queue_remove(q);
 
    return removed_element;
}
 
int stack_is_empty(queue_t * q) {
    return queue_is_empty(q);
}
 
int stack_count(queue_t * q) {
    return queue_count(q);
}
 
/* Simulated stack operations END */
 
/* Queue operations START */
 
int queue_count(queue_t * q) {
    return q->count;
}
 
queue_t *
queue_allocate(int n) {
    queue_t *queue;
 
    queue =(queue_t*) malloc(sizeof(queue_t));
    if (queue == NULL)
        return NULL;
    queue->max = n;
 
    //queue->arr = malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;
 
    return queue;
}
 
void queue_insert(queue_t * q, int v) {
    if (q->count == q->max)
        return;
 
    q->rear = (q->rear + 1) % q->max;
    q->arr[q->rear] = v;
    q->count++;
}
 
int queue_remove(queue_t * q) {
    int retval;
 
    /* magic number if queue is empty */
    if (q->count == 0)
        return QUEUE_EMPTY_MAGIC;
 
    q->front = (q->front + 1) % q->max;
    retval = q->arr[q->front];
    q->count--;
 
    return retval;
}
 
int queue_is_empty(queue_t * q) {
    return (q->count == 0);
}
 
/* Queue operations END */
 
/* For demo */
void queue_display(queue_t * q) {
    int i = (q->front + 1) % q->max, elements = queue_count(q);
 
    while (elements--) {
        printf("[%d], ", q->arr[i]);
        i = (i >= q->max) ? 0 : (i + 1);
    }
}
 

