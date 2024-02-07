#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/wait.h>
int count=0; 
int main()
{
    pid_t id;
    id=fork();
    if(0==id)
    {
        count ++;
	printf("I am child\n");
	
        printf("child pid:%d\t ppid:%d\n",getpid(),getppid());
     sleep(3);
        printf("child pid:%d\t ppid:%d\n",getpid(),getppid());
    }
    
    else 
    {
	    printf("I am parent\n");
     printf("child pid:%d\t ppid:%d\n",getpid(),getppid());
     wait(NULL);
    // sleep(10);
    }
}
