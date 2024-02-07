#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int a=10,b=20,sum=5;
    pid_t id;
    id=fork();
    if(0==id)
    {
      sum=a+b;
      printf("addition is %d\n",sum);
      printf("pid ofchild:=%d\n,parent:=%d\n",getpid(),getppid());
      sleep(1000); 
      
    }
    else
    {
      printf("pid of parent:=%d\n,child:=%d\n",getppid(),getpid()); 
        
    }
}
