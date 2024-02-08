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

void InsertAfter(struct node *start, int data, int item)
{
    if ( start == NULL )
    {
        printf("Empty Link List\n");
        return;
    }

    while (start != NULL)
    {
        if (start->data == item)
        {
            struct node *p = (struct node *) malloc(sizeof(struct node));
            p->data = data;
            p->prev = start;
            p->next = start->next;
            
            if (start->next != NULL)
                start->next->prev = p;
            start->next = p;
            printf("%d inserted after %d in link list\n",data,item);
            return;
        }
        start = start->next;
    }
    printf("%d element not found in linked list\n",item);
}

struct node * InsertBefore(struct node *start, int data, int item)
{
    struct node *temp = start;

    if (start == NULL)
    {
        printf("Empty link list\n");
        return start;
    }

    while (temp != NULL)
    {
        if (temp->data == item)
        {
            struct node *p = (struct node *) malloc(sizeof(struct node));
            p->data = data;
            p->prev = temp->prev;
            p->next = temp;

            if (temp->prev != NULL) // update next address of previous node if it is not first node
                p->prev->next = p;
            else                    // if adding before first node, start will change to new node created
                start = p;
            temp->prev = p; 
            return start;
        }
        temp = temp->next;
    }
    printf("%d element not found in linked list\n",item);
    return start;
}

struct node *DelBegining(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty link list\n");
        return start;
    }

    struct node *temp=start;
    if (temp->next != NULL)
        temp->next->prev = NULL;
    temp = temp->next;
    free(start);
    return temp;
}

struct node *DelEnd(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty link list\n");
        return start;
    }

    struct node *temp=start;
    if(temp->next == NULL)
    {
        free(temp);
        return NULL;
    }

    while( temp->next != NULL)
        temp = temp->next;
    
    temp->prev->next = NULL;
    free(temp);
    return start;
    
}

int main()
{
    struct node *start = NULL;
    int choice,data,item;
    while(1)
    {
        printf("\n1. Display\n");
        printf("2. Insert from begining\n");
        printf("3. Insert at end\n");
        printf("4. Add after\n");
        printf("5. Insert before\n");
        printf("6. Delete from begining\n");
        printf("7. Delete from end\n");
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
            printf("Enter element to be inserted :");
            scanf("%d",&data);
            start = InsertBeg(start,data);
            break;
        case 3:
            printf("Enter element to be inserted :");
            scanf("%d",&data);
            start = InsertEnd(start,data);
            break;
        case 4:
            printf("Enter element to be entered : ");
            scanf("%d",&data);
            printf("Enter element after which to be inserted : ");
            scanf("%d",&item);
            InsertAfter(start,data,item);
            break;
        case 5:
            printf("Enter element to be entered : ");
            scanf("%d",&data);
            printf("Enter element before which to be inserted : ");
            scanf("%d",&item);
            start = InsertBefore(start,data,item);
            break;
        case 6:
            start = DelBegining(start);
            break;
        case 7:
            start = DelEnd(start);
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