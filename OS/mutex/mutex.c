#include<stdio.h>
#include<pthread.h>

int count =0;
pthread_mutex_t countMutex;

	void* incThread(void* data)
	{
	while(1)
	{
	 pthread_mutex_lock(&countMutex);
	 printf("Inc Thread:%d\n",++count);
	 pthread_mutex_unlock(&countMutex);
	}
	}
	

	 void* decThread(void* data)
        {
        while(1)
        {
        pthread_mutex_lock(&countMutex);
        printf("Dec Thread:%d\n",--count);
        pthread_mutex_unlock(&countMutex);
        }
	}


 int main()
{
 pthread_t incId,decId;
 pthread_mutex_init(&countMutex,NULL);
 pthread_create(&incId,NULL,incThread,NULL);
 pthread_create(&decId,NULL,decThread,NULL);
 pthread_join(incId,NULL);
 pthread_join(decId,NULL);
 pthread_mutex_destroy(&countMutex);
 
 return 0;
}

