#include<stdio.h>

/* Graph
    0 ----- 1
    | \     |
    |   \   |
    |     \ |
    3-------2
     \     /
      \   /
        4
      /   \
     /      \
    5        6
*/

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

void DFS(int current_vertex)
{
    printf("%d ",current_vertex);
    visited[current_vertex] = 1;
    for (int destination_vertex = 0; destination_vertex < 7; destination_vertex++)
    {
        if (a[current_vertex][destination_vertex] == 1 && !visited[destination_vertex])
            DFS(destination_vertex);
    }  
}

int main()
{
    //DFS Implementation
    int i = 1;  // start vertex
    DFS(i);
    printf("\n");
    return 0;
}