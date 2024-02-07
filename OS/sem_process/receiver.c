#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <sys/types.h>
#include<unistd.h>

int main()
{	
	int unlink;
	int *val;

	sem_t *sem_fdrx=sem_open("/sem_r2",O_CREAT | O_RDWR , 0644 ,  0);
	if (sem_fdrx == SEM_FAILED)	
		perror("TX :  sem_r failed to open : \n");

        sem_t *sem_fdtx=sem_open("/sem_s2",O_CREAT | O_RDWR , 0644 ,  1);
        if (sem_fdtx == SEM_FAILED)
                perror("TX :  sem_s failed to open : \n");
//while(1)
{	
	printf("RX : Waiting for lock\n");
	sem_wait(sem_fdrx);
	printf("RX : SUCESS\n\n");
	sem_post(sem_fdtx);
	printf("RX : Unlocked\n");
}

//	unlink =sem_unlink("/sem_r");
//	if ( unlink == -1 )
//		printf("TX :  sem unlink failed : sem_rx\n");
	
	sem_destroy(sem_fdrx);
	sem_destroy(sem_fdtx);
	
	return 0;
}
