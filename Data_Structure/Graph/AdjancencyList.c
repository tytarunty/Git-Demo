#include<stdio.h>
#include<stdlib.h>

struct Vertex{
    int info;
    struct Vertex *nextVertex;
    struct Edge *firstEdge;
} *start = NULL;

struct Edge{
    struct Vertex *destVertex;
    struct Edge *nextEdge;
};

struct Vertex * findVertex(int vertex)
{
    struct Vertex *temp = start;

    while(temp != NULL)
    {
        if (temp->info == vertex)
        {
            return temp;
        }
        temp = temp->nextVertex;
    }
    return NULL;
}

void InsertVertex(int u)
{
    struct Vertex *newVertex = (struct Vertex *)malloc(sizeof(struct Vertex)),*temp;

    newVertex->info = u;
    newVertex->firstEdge  = NULL;
    newVertex->nextVertex = NULL;
    if (start == NULL)
    {
        start = newVertex;
        return;
    }

    temp = start;
    while(temp->nextVertex != NULL)
    {
        temp = temp->nextVertex;
    }
    temp->nextVertex = newVertex;
}

void InsertEdge(int u, int v)
{
    struct Edge *temp;
    struct Vertex *locu, *locv;
    if ( start == NULL){
        printf("Empty Graph\n");
        return;
    }

    locu = findVertex(u);
    locv = findVertex(v);
    if (locu == NULL)
    {
        printf("Source vertex is not present\n");
        return;
    }
    if (locv == NULL)
    {
        printf("Destination vertex is not present\n");
        return;
    }

    struct Edge *newEdge = (struct Edge * )malloc(sizeof(struct Edge));
    newEdge->destVertex = locv;
    newEdge->nextEdge = NULL;
    temp = locu->firstEdge;
    if (temp == NULL) // no edged present for vertex
    {
        locu->firstEdge = newEdge;
        return;
    }
    while (temp->nextEdge !=NULL) //iterate edge till last node of edge link list
        temp = temp->nextEdge;
    temp->nextEdge = newEdge;  //update nextEdge of last node link list to newly created edge
}

void Display(void)
{
    struct Vertex *vertex;
    struct Edge *edge;
    vertex = start;

    if (vertex == NULL)
    {
        printf("Empty Graph\n");
        return;
    }

    while ( vertex != NULL )
    {
        edge = vertex->firstEdge;
        printf("%d  =  ",vertex->info);
        while( edge != NULL)
        {
            printf("%d --> ", edge->destVertex->info);
            edge = edge->nextEdge;
        }
        printf("\n");
        vertex = vertex->nextVertex;
    }
    printf("\n");
}

int main()
{
    int choice,u,source,destination;

    while(1)
    {
        printf("Enter choice : ");
        printf("\n1. Insert a Vertex\n");
        printf("2. Insert an Edge\n");
        printf("3. Delete a Vertex\n");
        printf("4. Delete an Edge\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
                printf("Enter the vertex to be inserted : ");
                scanf("%d",&u);
                InsertVertex(u);
                break;
            case 2 :
                printf("Enter Source : ");
                scanf("%d",&source);
                printf("Enter Destination : ");
                scanf("%d",&destination);
                InsertEdge(source,destination);
                break;
            case 5 : 
                Display();
                break;
            case 6 : 
                exit(1);
            default : 
                printf("Enter correct choice\n");
        }
    }
    return 0;
}