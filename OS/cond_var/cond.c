#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

int event = 0 ;
pthread_mutex_t event_wait,event_set;
pthread_cond_t event_condvar;

 void* event_setter(void* data)
	{
	pthread_mutex_lock(&event_set);
	printf("ES : Grab mutex , event : %d\n",event);
	event=1;
	printf("ES : Event is set\n");
	pthread_mutex_unlock(&event_set);
	printf("ES : Unlock mutex\n");
	pthread_cond_signal(&event_condvar);
	}

 void* wait_for_event(void* data)
        {
	pthread_mutex_lock(&event_wait);
	printf("WE : Grab mutex, event: %d\n",event);
	while (event != 1)
	{
		printf("WE : Unlock mutex, cond waiting state\n");
		pthread_cond_wait(&event_condvar,&event_wait);
		printf("WE : Waiting for condvar , Checking condition\n");
	}
	printf("WE : condvar condition satisfied\n");
	pthread_mutex_unlock(&event_wait);
	printf("WE : Unlock mutex\n");
        }

 int main()
	{
	pthread_t id1,id2;
	pthread_cond_init(&event_condvar,NULL);
	pthread_create(&id1,NULL,wait_for_event,NULL);
	pthread_create(&id2,NULL,event_setter,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_cond_destroy(&event_condvar);
	return 0;
	}

