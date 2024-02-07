#include <semaphore.h>
#include<stdio.h>
#include<pthread.h>

sem_t sem_in_proc;
sem_t sem_proc_in;
int a,b;

void *input_thread(void *data)
{
	while(1)
	{
		printf("IN : \n");
		sem_wait(&sem_proc_in);
		printf("Enter two numbers\n");
		scanf("%d",&a);
		scanf("%d",&b);
		printf("IN : a :%d , b : %d\n",a,b);
		sem_post(&sem_in_proc);
	}
}

void *proc_thread(void *data)
{
	int sum;
	while(1)
	{
		printf("PR : \n");
		sem_wait(&sem_in_proc);
		sum=a+b;
		printf("PROC : sum = %d\n",sum);
		sem_post(&sem_proc_in);
	}
}

int main()
{
	pthread_t in_id,proc_id;
	sem_init(&sem_in_proc,0,0);
	sem_init(&sem_proc_in,0,1);
	pthread_create(&in_id,NULL,input_thread,NULL);
	pthread_create(&proc_id,NULL,proc_thread,NULL);
	pthread_join(in_id,NULL);
	pthread_join(proc_id,NULL);
	sem_destroy(&sem_in_proc);
	sem_destroy(&sem_proc_in);
	return 0;
}
