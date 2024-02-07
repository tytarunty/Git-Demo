#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_rwlock_t rw_lock;

void *lcd(void *data)
{
	printf("LCD Thread Start\n");
	pthread_rwlock_rdlock(&rw_lock);
	printf("LOCKED LCD\n");
	sleep(3);
	printf("LCD\n");
	pthread_rwlock_unlock(&rw_lock);
	printf("UNLOCKED LCD\n");

}

void *serial(void *data)
{
	printf("Serail Thread Start\n");
	pthread_rwlock_rdlock(&rw_lock);
	printf("LOCKED SERIAL\n");
	sleep(3);
	printf("Serial\n");
	pthread_rwlock_unlock(&rw_lock);
	printf("UNLOCKED SERIAL\n");
}
void *input(void *data)
{
	printf("Input Thread Start\n");
	pthread_rwlock_wrlock(&rw_lock);
	printf("LOCKED INPUT\n");
	sleep(3);
	printf("Input\n");
	pthread_rwlock_unlock(&rw_lock);
	printf("UNLOCKED INPUT\n");
}

int main()
{	
	pthread_t id1,id2,id3;
	pthread_rwlock_init(&rw_lock,NULL);
	pthread_create(&id1,NULL,lcd,NULL);
	pthread_create(&id2,NULL,serial,NULL);
	pthread_create(&id3,NULL,input,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);
	pthread_rwlock_destroy(&rw_lock);
	return 0;
}
