#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define BUFF 1024


int main()
{
  pid_t id;
  int a,b;
  unsigned char buff[BUFF];
  int pipe1[2],pipe2[2];
  pipe(pipe1);
  pipe(pipe2);
  id=fork();
  if(id==0)
   { 
     
     close(pipe1[1]);
     read(pipe1[0],buff,BUFF);
     char *k=buff;
     while(*k!='\0')
     {
       if(*k==',')
           b=atoi(k+1);
       k++;
      }
     
    a=atoi(buff);
    close(pipe2[0]);
    k = a+b;
    printf("No. received from parent to add is %d %d\n",a,b);
    write(pipe2[1],&k,BUFF);
   }

 else
   {
    close(pipe1[0]);
    write(pipe1[1],"2,40",BUFF);
    close(pipe2[1]);
    read(pipe2[0],&buff,BUFF);
    printf("\n The sum inside parent is %d\n",*buff);
    return 0;
   }
}
