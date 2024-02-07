#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void PrintQueue(struct node *front)
{
    if (front == NULL)
    {
        printf("Empty Queue\n");
        return;
    }

    while (front != NULL)
    {
        printf("%d ",front->data);
        front = front->next;
    }
    printf("\n");
}

//Insert at end
struct node * enqueue(struct node *front, int data)
{
    struct node *p = (struct node *) malloc(sizeof(struct node)),*last=front;

    if( p == NULL)
    {
        printf("Queue Overflow\n");
        return front;
    }

    p->data = data;
    p->next = NULL;
    if (front == NULL)
    {
        return p;
    }

    while(last->next != NULL)
        last = last->next;
    last->next = p;
    return front;
}

//delete from begining
struct node * dequeue(struct node *front)
{
    struct node *temp=front;
    if ( front == NULL)
    {
        printf("Queue Undeflow\n");
        return front;
    }
    printf("%d dequeued\n", front->data);
    front = front->next;
    free(temp);
    return(front);
}

int main()
{
    struct node *front=NULL;
    int data,choice;

    while(1)
    {
        printf("\n1. Print Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            PrintQueue(front);        
            break;
        case 2:
            printf("Enter data to enqueue : ");
            scanf("%d",&data);
            front=enqueue(front,data);
            break;
        case 3:
            front=dequeue(front);
            break;
        case 4:
            exit(1);
            break;
        default:
        printf("Enter correct choice\n");
            break;
        }
    }

    return 0;
}