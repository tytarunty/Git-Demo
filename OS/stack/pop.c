#include<stdio.h>

int pop(int *top, int stack[]);
int pop(int *top,int stack[])
{
  // int *value;
   if(*top==-1)
   {
     printf("stack is underflown\n");
   }
   //*value=
   //*top=(*top--);
   return stack[(*top)--];
}

