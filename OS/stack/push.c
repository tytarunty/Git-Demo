

#include<stdio.h>

void push(int MAX,int *value,int *top,int stack[]);
void push(int MAX,int *value,int *top,int stack[])
 {
    // printf("value=%d",value);
   if(*top==MAX-1)
      {
        printf("stack is overflown\n");
	  return;
      }
   stack[++(*top)]=*value; 
 }
