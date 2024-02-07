#include<stdio.h>
#include<pthread.h>

int count=0;

 void *incthread(void* data)
	{
	while(1)
	{
	printf("Inc Thread:%d\n",count++);
	
	}
	}


 void *decthread(void* data)
        {
        while(1)
        {
        printf("Dec Thread:%d\n",count--);
        
        }
        }

  int main()
 {
 pthread_t incId,decId;
 pthread_create(&incId,NULL,incthread,NULL);
 pthread_create(&decId,NULL,decthread,NULL);
 pthread_join(incId,NULL);
 pthread_join(decId,NULL);
 
 return 0;
}



