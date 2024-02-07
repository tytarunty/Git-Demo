#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
sem_t sem_count;
  
	void* inc_thread(void *data)
	 {
	  while(1)
           {
	       sem_wait(&sem_count);
	       printf("Inc Thread:%d\n",++count);
	       sem_post(&sem_count);
	   }
         }                      


   	 void* dec_thread(void *data)
	  {
   	   while(1)
  	    {
	       sem_wait(&sem_count);
               printf("Dec Thread:%d\n",--count);
	       sem_post(&sem_count);
             }
	  }     


 int main()
   {
    sem_init(&sem_count,0,1);
    pthread_t inc_id,dec_id;
    pthread_create(&inc_id,NULL,inc_thread,NULL);
    pthread_create(&dec_id,NULL,dec_thread,NULL);
    pthread_join(inc_id,NULL);
    pthread_join(dec_id,NULL);
    sem_destroy(&sem_count);

    return 0;
   }
