#include<stdio.h>

struct node {
    int data;
    struct node * ; 
};

void main()
{
    struct node *start=NULL;
    int choice;

    while (1)
    {
        printf("1. Insert from begining\n");
        
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            InsertBegining(start);
            break;
        default:
            printf("Enter correct choice\n");
        }
        printf("1. ")
    }
    return 0;
}

void InsertBegining(struct node *start)
{
    
}