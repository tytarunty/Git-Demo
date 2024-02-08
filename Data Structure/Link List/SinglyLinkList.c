#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next; 
};

int isNull(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty LinkList\n");
        return 1;
    }
    return 0;
}

void PrintLinkList(struct node *start)
{
    // time complexity : O(n)
    if (isNull(start))
        return;
    
    while (start != NULL)
    {
        printf("%d --> ",start->data);
        start=start->next;
    }
}

struct node* InsertBegining(struct node *start, int data)
{
    // time complexity : O(1)
    struct node *p=(struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->next = start;
    return p;
}

struct node * InsertEnd(struct node *start,int data)
{
    // time complexity : O(n)
    struct node *p=(struct node *)malloc(sizeof(struct node)),*last=start;
    p->data=data;
    p->next=NULL;
    if (isNull(last))
    {
        return p;
    }
    while(last->next != NULL)
    {
        last=last->next;
    }
    last->next=p;
    return start;
}

struct node * InsertAtIndex(struct node *start,int data,int index)
{
    struct node *p=(struct node *)malloc(sizeof(struct node)),*temp=start;
    p->data = data;
    int i=0;
    while( i < index )
    {
        temp=temp->next;
        i++;
    }
    p->next = temp->next;
    temp->next = p;
    return start;
}

void AddAfter(struct node *start,int data,int item)
{
    while ( start != NULL )
    {
        if (start->data == item)
        {
            struct node *p = (struct node *) malloc(sizeof(struct node));
            p->data = data;
            p->next = start->next;
            start->next = p;
            printf("%d inserted after %d in link list\n",data,item);
            return;
        }
    start = start->next;
    }
    printf("%d element not found in Link List",item);
    return;
}

struct node * AddBefore(struct node *start,int data,int item)
{
    struct node *temp=start;
    
    if (start == NULL)  // if link list is empty
    {
        printf("Empty Link List\n");
        return start;
    }

    if (start->data == item) // if data to be inserted before first node
    {
        struct node *p= (struct node *) malloc(sizeof(struct node));
        p->data = data;
        p->next = start;
        return p;
    }

    while ( temp->next != NULL)
    {
        if (temp->next->data == item)
        {
            struct node *p= (struct node *) malloc(sizeof(struct node));
            p->data = data;
            p->next = temp->next;
            temp->next = p;
            return start;
        }
        temp = temp->next;
    }
    printf("%d element not found in Link List",item);
    return start;
}

struct node * Reverse(struct node *start)
{
    struct node *prev = NULL, *next = NULL, *current = start;

    while ( current != NULL)
    {
        next = current->next;
        current->next = prev ; 
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    struct node *start=NULL;
    int choice,data,index,item;

    while (1)
    {
        printf("\n1. Print Link List\n");
        printf("2. Insert from begining\n");
        printf("3. Insert at end\n");
        printf("4. Insert at index\n");
        printf("5. Insert after node\n");
        printf("6. Insert before node\n");
        printf("7. Reverse Link List\n");
        printf("10. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            PrintLinkList(start);
            printf("\n");
            break;
        case 2:
            printf("Enter Data : ");
            scanf("%d",&data);
            start = InsertBegining(start,data);
            break;
        case 3:
            printf("Enter Data : ");
            scanf("%d",&data);
            start=InsertEnd(start,data);
            break;
        case 4:
            printf("Enter Data : ");
            scanf("%d",&data);
            printf("Enter index at which data need to be inserted : ");
            scanf("%d",&index);
            start=InsertAtIndex(start,data,index);
            break;
        case 5:
            printf("Enter Data : ");
            scanf("%d",&data);
            printf("Enter Item after which node to be inserted : ");
            scanf("%d",&item);
            AddAfter(start,data,item);
            break;
        case 6:
            printf("Enter Data : ");
            scanf("%d",&data);
            printf("Enter Item before which node to be inserted : ");
            scanf("%d",&item);
            start = AddBefore(start,data,item);
            break; 
        case 7:
            start = Reverse(start);  
            break;         
        case 10:
            exit(0);
            break;
        default:
            printf("Enter correct choice\n");
            break;
        }
    }
    return 0;
}
