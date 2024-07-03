#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int queue[MAX],front = -1, rear = -1;

void PrintQueue()
{
    if (front == -1 || front == rear+1)
    {
        printf("Queue is empty\n");
        return;
    }
    for ( int i = front ; i <= rear ;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void enqueue(int data)
{
    if (rear == MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
}

void dequeue()
{
    if (front == -1 || front == rear+1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d is dequeued\n",queue[front]);
    front++;
}

int main()
{
    int choice, data;

    while(1)
    {
        printf("1. Print Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            PrintQueue();        
            break;
        case 2:
            printf("Enter data to enqueue : ");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 3:
            dequeue();
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