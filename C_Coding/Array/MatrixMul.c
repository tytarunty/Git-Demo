#include<stdio.h>

#define ROW1 2
#define COL1 2
#define ROW2 2
#define COL2 3

int main()
{
    int arr1[ROW1][COL1] = {{4,5},{3,2}};
    int arr2[ROW2][COL2] = {{2,6,3},{-3,2,4}};
    int arr3[ROW1][COL2] = {};
    for (int i=0 ; i < ROW1 ; i++)
        for (int j=0 ; j<COL2 ; j++)
            for (int k = 0 ; k < ROW2 ; k++)
                arr3[i][j] += arr1[i][k] * arr2[k][j];

        for (int i=0 ; i < ROW1 ; i++)
        {
            for (int j=0 ; j<COL2 ; j++)
            {
            printf("%d ", arr3[i][j]);
            }
            printf("\n");
        }
                

    return 0;
}