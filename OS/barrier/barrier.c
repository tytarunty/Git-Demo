#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t barrier;

void *lcd(void *data)
{
	printf("LCD init\n");
	sleep(4);
	pthread_barrier_wait(&barrier);
	printf("LCD START\n");
}

void *serial(void *data)
{
	printf("Serail init\n");
	sleep(2);
	pthread_barrier_wait(&barrier);
	printf("SERIAL START\n");
}

void *gsm(void *data)
{
	printf("GSM init\n");
	sleep(9);
	pthread_barrier_wait(&barrier);
	printf("GSM START\n");
}

int main()
{
	pthread_t id1,id2,id3;
        pthread_barrier_init(&barrier,NULL,3);
	pthread_create(&id1,NULL,lcd,NULL);
	pthread_create(&id2,NULL,serial,NULL);
	pthread_create(&id3,NULL,gsm,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);
	pthread_barrier_destroy(&barrier);
	return 0;
}
