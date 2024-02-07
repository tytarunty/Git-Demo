#include<stdio.h>

void display(int *top,int stack[]);
void display(int *top,int stack[])
{
  int i;
  if(*top==-1)
    {
    printf("stack is underflown\n");
printf("top=%d",*top);
     return;
     }
  for(i=*top; i>=0;i--)
   printf("%d->\n",stack[i]);
}

