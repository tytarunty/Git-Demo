#include<stdio.h>
#include<stdlib.h>
#include"stack_lib.h"

#define MAX 5
int top=-1; 
int stack[MAX];

int main()
{
     int value,choice;
     while(1)
      {
        printf("enter your choice\n");
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.display\n");	
	printf("4.exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	   {
		case 1:
			printf("enter any value\n");
			scanf("%d",&value);
			push(MAX,&value,&top,stack);
			break;
		case 2:
			value=pop(&top,stack);
			break;
		case 3:
			display(&top,stack);
			break;
		case 4:
			exit(1);
		default:
			printf("invalid choice\n please enter valid choice");
	   }
       }
}
