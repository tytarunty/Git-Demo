#include<stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5
#define N_DIRECTION 4
int direction[][2] = {
    {-1,0}, //Up
    {1,0},  //Down
    {0,-1}, //Left
    {0,1},   //Right
    {-1,-1},//Top-left
    {-1,1}, //Top-right
    {1,-1}, //Bottom-left
    {1,1}  //Bottom-right
};

int isValid(int grid[ROW][COL],int visited[ROW][COL],int row, int col, int x, int y,int prevHeight)
{
    return (x>=0 && x<row && y>=0 && y<col  && // check boundaries
    !visited[x][y] &&                                              // check if not visited
    grid[x][y] >= prevHeight);                                     // check height for water flow
}

void dfs(int grid[5][5],int row, int col, int x,int y,int visited[ROW][COL]){
    visited[x][y] = 1;
    for ( int i = 0 ; i < N_DIRECTION ; i++)
    {   
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if(isValid(grid,visited,row,col,nx,ny,grid[x][y]))
            dfs(grid,row,col, nx,ny,visited);
    }
    HASH_FIND_INT
}

int main()
{
    int grid[ROW][COL] = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    int pacific[ROW][COL] = {0};
    int atlantic[ROW][COL] = {0};

    // perform dfs for pacific ocean (top and left edge)
    for(int i = 0 ; i < COL ; i++)    
        dfs(grid,ROW, COL, 0,i,pacific);  // Top edge
    for(int i = 0 ; i < ROW ; i++)    
        dfs(grid,ROW, COL, i,0,pacific);  // Left Edge
    
    // perform dfs for atlantic ocean (bottom and right edge)
    for(int i = 0 ; i < COL ; i++)    
        dfs(grid,ROW, COL, ROW-1,i,atlantic); // Bottom edge
    for(int i = 0 ; i < ROW ; i++)    
        dfs(grid,ROW, COL, i,COL-1,atlantic);  // Right edge

    for (int i = 0 ; i < ROW ; i++){
        for(int j = 0 ; j< COL ; j++){
            if(pacific[i][j] == atlantic[i][j])
                printf("%d %d\n",i,j);
        }
    }
    printf("Hello World\n");
    
    return 0;
}