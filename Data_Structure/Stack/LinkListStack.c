#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *start)
{
    if ( start == NULL)
    {
        printf("Empty Stack\n");
        return;
    }

    while ( start != NULL)
    {
        printf("%d --> ",start->data);
        start = start->next;
    }
}

// Insert at begining of link list
struct node * push(struct node *top, int data)
{
    struct node *p = (struct node *) malloc(sizeof(struct node));

    if ( p == NULL)
    {
        printf("STACK OVERFLOW\n");
        return p;
    }
    p->data = data;
    p->next = top;
    return p;
}

// Delete from begining of Link list
struct node * pop(struct node *top)
{
    if (top == NULL)
    {
        printf("STACK UNDERFLOW\n");
        return top;
    }
    struct node *temp = top;
    printf("\n%d is poped out of stack\n",top->data);
    top = top->next;
    free(temp);
    return top;
}

int main()
{
    struct node *top = NULL ;
    while(1)
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
            display(top);
            break;
        case 2:
            printf("Enter data to insert in stack : ");
            scanf("%d",&data);
            top = push(top,data);
            break;
        case 3:
            top = pop(top);
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