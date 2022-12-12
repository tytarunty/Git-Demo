#include<stdio.h>

#define CHECK_EMPTY_LIST(start) if(start == NULL) \
                                    { printf("%s","Empty Link List\n"); \
                                        return ; }

struct node {
    int data;
    struct node * link; 
};

struct node* InsertBegining(struct node *start, int data);
void PrintLinkList(struct node *start);


void main()
{
    struct node *start=NULL;
    int choice,data;

    while (1)
    {
        printf("1. Insert from begining\n");
        printf("2. Print Link List\n");
        printf("10. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data : ");
            scanf("%d",&data);
            start = InsertBegining(start,data);
            break;
        case 2:
            PrintLinkList(start);
            printf("\n");
            break;
        case 10:
            exit(0);
        default:
            printf("Enter correct choice\n");
        }
    }
    return 0;
}

struct node* InsertBegining(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = start;
    return temp;
}

void PrintLinkList(struct node *start)
{
    CHECK_EMPTY_LIST(start)
    
    while (start != NULL)
    {
        printf("%d --> ",start->data);
        start=start->link;
    }
}
