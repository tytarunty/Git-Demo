#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

 void* thread2(void* data)
	{
	printf("RTC thread:1\n");
	
	}

 void* thread1(void* data)
        {
        printf("RTC thread:2\n");
		while(1)
		{
			int a;
		}
        }

 int main()
	{

	pthread_t id1,id2;
///	printf("before thread:\n");
	pthread_create(&id1,NULL,thread1,NULL);
	pthread_create(&id2,NULL,thread2,NULL);
//	printf("after thread:\n");
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
	}
/*
 pthread_t incId,decId;
 pthread_mutex_init(&countMutex,NULL);
 pthread_create(&incId,NULL,incThread,NULL);
 pthread_create(&decId,NULL,decThread,NULL);
 pthread_join(incId,NULL);
 pthread_join(decId,NULL);
 pthread_mutex_destroy(&countMutex);
*/
