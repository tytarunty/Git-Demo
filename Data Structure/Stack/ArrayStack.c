// WAP for implmentation of stack using array data structure

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void Print(int stack[],int top)
{
    if ( top < 0 )
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\n   STACK");
    for (int i=top ; i >= 0 ; i--)
    {
        printf("\n------------\n%5d",stack[i]);
    }
    printf("\n------------\n");
}

int push(int stack[], int data,int top)
{
    if  ( top == MAX -1)
    {
        printf("STACK OVERFLOW\n");
        return top;
    }
    top++ ;
    stack[top] = data ;
    return top;
}

int pop(int stack[], int top)
{
    if ( top == -1 )
    {
        printf("STACK UNDERFLOW\n");
        return top;
    }
    printf("%d is poped out of stack\n",stack[top]);
    top--;
    return top;
}


int main()
{
    int stack[MAX],top = -1;

    while (1)
    {
        int choice,data;
        printf("\nEnter your choice\n");
        printf("1. Display all stack element\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Exit\n");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            Print(stack,top);
            break;
        case 2:
            printf("Enter data to be entered : ");
            scanf("%d",&data);
            top = push(stack,data,top);
            break;
        case 3:
            top = pop(stack,top);
            break;    
        case 4:
            exit(1);
            break;
        default:
            printf("Enter correct choice\n");
            break;
        }

    }
    

}