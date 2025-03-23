#if 0
#include<stdio.h>
#include<stdlib.h>

int a = 5;              //Allocates memory on  : DATA 
int b;                  //Allocates memory on  : BSS
int c = 0;              //Allocates memory on  : BSS

static int d = 10;      //Allocates memory on  : DATA
static int e;           //Allocates memory on  : BSS
static int f = 0;       //Allocates memory on  : HEAP

void foo(){
    int g = 10;         //Allocates memory on  : HEAP
    int h;              //Allocates memory on  : HEAP
    static int i;       //Allocates memory on  : HEAP
    static int j = 20;  //Allocates memory on  : HEAP
    int *ptr1 = (int *) malloc(sizeof(int) *10);  //Allocates memory on  : HEAP
}

int main(){
    int i = 10;
    static int k = 20;  //Allocates memory on  : HEAP
    int *ptr2 = (int *) malloc(sizeof(int) *10);  //Allocates memory on  : HEAP 
    foo();
    return 0;
}
#endif

#include<stdio.h>
#define ROW 5
#define COL 5
#define N_DIRECTION 4

int dir[][2] = {
    {-1,0}, //Up
    {1,0},  //Down
    {0,-1}, //Left
    {0,1},   //Right
    {-1,-1},//Top-left
    {-1,1}, //Top-right
    {1,-1}, //Bottom-left
    {1,1}  //Bottom-right
}

int isValid(){

}



int main(){
    int grid[ROW][COL] = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    int pacific[ROW][COL] = {0};
    int atlantic[ROW][COL] = {0};
}