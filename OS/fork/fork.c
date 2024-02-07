#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>

int main()
{
pid_t id1,id2;
id1 = fork();
id2 = fork();
printf("fork: %d, id1 :  %d , id2 : %d \n",getpid(),id1,id2);
	if(id1==0)
	{
	printf("P1-child,  pid: %d , ppid : %d\n",getpid(),getppid());
	        if(id2 == 0 )
		{
			printf("P3-child,  pid: %d , ppid : %d\n",getpid(),getppid());
		}                 
		else
		{
			printf("P1-parent, pid: %d , ppid : %d\n",getpid(),getppid());
		}                                                                                                                                                                                                                                           
	}
	else
	{
//	printf("id : %d\n",id1);		
                if(id2 == 0 )            
		{
                        printf("P2-child,  pid: %d , ppid : %d\n",getpid(),getppid());
                }       
		else    
		{
                        printf("P0-parent, pid: %d , ppid : %d\n",getpid(),getppid());
                }                        
	}	


return 0;
}
