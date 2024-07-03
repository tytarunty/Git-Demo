#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void CreateArray(struct myArray *a, int tSize, int uSize)
{
    (*a).total_size = tSize;                            // a->total_size = tSize;
    (*a).used_size  = uSize;                            // a->used_size  = uSize;
    (*a).ptr = (int *) malloc(tSize*sizeof(int));       // a->ptr = (int *) malloc(tSize*sizeof(int));
}

void Show(struct myArray *a )
{
    for (int i=0 ; i < a->used_size ; i++)
    {
        printf("%d\n",(a->ptr[i]));
    }
}

void SetValue(struct myArray *a)
{
    int n;
    for (int i=0 ; i < a->used_size ; i++)
    {
        printf("Enter Element : ");
        scanf("%d",&n);
        a->ptr[i] = n;
    }
    
}

int main()
{
    struct myArray marks;
    CreateArray(&marks, 100, 5 );
    SetValue(&marks);
    Show(&marks);
    return 0;
}