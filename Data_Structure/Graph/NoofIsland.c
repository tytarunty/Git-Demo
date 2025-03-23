//top, bottom,left,right
#define N_DIRECTION 4
int direction[][2] = {
    {-1,0}, //Up
    {1,0},  //Down
    {0,-1}, //Left
    {0,1}   //Right
    {-1,-1},//Top-left
    {-1,1}, //Top-right
    {1,-1}, //Bottom-left
    {1,1}.  //Bottom-right
};
int n_row,n_col;

int isValid(char **grid,int visited[][n_col],int row, int col, int x, int y)
{
    return (x>=0 && x<row && y>=0 && y<col && grid[x][y] == '1' && // check boundaries
    !visited[x][y]);                                               // check if not visited
}

void dfs (char** grid,int row, int col, int x,int y,int visited[][n_col]){
    if(isValid(grid,visited,row,col,x,y))
    {
        //grid[x][y]='2';
        visited[x][y] = 1;
        for ( int i = 0 ; i < N_DIRECTION ; i++)
        {   
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            dfs(grid,row,col, nx,ny,visited);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    n_row = gridSize, n_col = *gridColSize ; 
    int visited[n_row][n_col]={};
    for (int i=0; i< n_row ; i++){   
        for (int j=0 ; j< n_col ; j++){
            if (grid[i][j] == '1' && !visited[i][j]){
                ans++;
                dfs(grid,n_row,n_col,i,j,visited);
            }
                
        }
    }    
    return ans;
}