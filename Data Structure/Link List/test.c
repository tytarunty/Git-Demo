#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void PrintLL(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty Link List\n");
        return;
    }
    while (start !=NULL)
    {
        printf("%d --> ",start->data);
        start = start->next;
    }
}
struct node * InsertBeg(struct node *start,int data)
{
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->next = start;
    return p;
}

struct node* InsertEnd(struct node *start, int data)
{
    struct node *p= (struct node *) malloc(sizeof(struct node)),*last=start;
    p->data = data;
    p->next = NULL;

    if (start == NULL)
        return p;

    while ( last->next != NULL)
    {
        printf("%p\n",last);
        last = last->next;
    }
    last->next = p;
    return start;
}

int main()
{
    struct node *start=NULL;
    int choice,data;
    while(1)
    {
        printf("\n\n1. Print Link List\n");
        printf("2. Insert from begining\n");
        printf("3. Insert at end\n");
        printf("4. Insert at index\n");
        printf("10. Exit\n\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            PrintLL(start);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d",&data);
            start = InsertBeg(start,data);
            break;
        case 3:
            printf("Enter data : ");
            scanf("%d",&data);
            start = InsertEnd(start,data);
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Wrong Input Entered\n");
            break;
        }
    }
    return 0;
}