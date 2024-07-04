#include<stdio.h>

// QUEUE functions
#define MAX 100
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

int dequeue()
{
    int temp;
    if (front == -1 || front == rear+1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    temp  = queue[front];
    //printf("%d ",queue[front]);
    front++;
    return temp;
}
// QUEUE functions end


int main()
{
    //BFS Implementation
    int i=0;  // start node
    int node;
    int visited[7] = {0,0,0,0,0,0,0};  // mark all the nodes v in visited as unvisited (visited - 1, not visited-0)

    //adjacency matrix
    int a[7][7] = { 
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d ", i);   // print source node
    visited[i] = 1;     // update source node as visited 
    enqueue(i);         // enqueue source node in queue for exploration

    while (!(front == -1 || front == rear+1))   // iterate till the queue is not empty
    {
        int u = dequeue();                      // dequeue node from queue
        for (int j=0 ; j<7 ; j++)               // for each unvisited neighbour v of u
        {
            if ( a[u][j] == 1  && visited[j] == 0){     //if node is not visited and if there is edge 
                printf("%d ",j);                
                visited[j] = 1;                         // mark v as visited
                enqueue(j);
            }
        }
    }
    printf("\n");
    return 0;
}