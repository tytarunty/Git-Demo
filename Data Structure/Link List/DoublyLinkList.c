#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void Display(struct node *start)
{
    if ( start == NULL )
    {
        printf("empty link list\n");
        return;
    }

    while (start != NULL)
    {
        printf("%d --> ",start->data);
        start = start->next;
    }
}

struct node * InsertBeg(struct node *start,int data)
{
    struct node *p = (struct node *) malloc(sizeof(struct node));

    if ( p == NULL)
    {
        printf("Space not allocated\n");
        return start;
    }

    p->data = data;
    p->prev = NULL;
    p->next = start;
    return p;
}

struct node * InsertEnd(struct node *start,int data)
{
    struct node *p = (struct node *) malloc(sizeof(struct node)), *temp = start;
    if ( p == NULL)
    {
        printf("Space not allocated\n");
        return start;
    }

    p->data = data;
    p->next = NULL; // next of last node will always be NULL
    if (start == NULL) // if link list is empty
    {
        p->prev = NULL;
        return p;
    }

    // if link list is not empty, iterate till last node of link list
    while ( temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;
    p->prev = temp;
    return start;
}

int main()
{
    struct node *start = NULL;
    int choice,data;
    while(1)
    {
        printf("\n1. Display\n");
        printf("2. Insert from begining\n");
        printf("3. Insert at end\n");

        printf("10. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
        case 1:   
            Display(start);
            break;
        case 2:
            printf("Enter data to be inserted :");
            scanf("%d",&data);
            start = InsertBeg(start,data);
            break;
        case 3:
            printf("Enter data to be inserted :");
            scanf("%d",&data);
            start = InsertEnd(start,data);
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Enter correct choice\n");
            break;
        }
    }
    return 0;
}