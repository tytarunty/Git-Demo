#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<errno.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include<stdio.h>
#define mem "/shm_mem"

int main()
{
	int fd= shm_open(mem, O_RDWR | O_CREAT, 0744 );
	if ( -1 == fd)
	{
		perror("SHM OPEN");
		exit(EXIT_FAILURE);
	}

	int trun = ftruncate(fd, sizeof(int));
	if (-1 == trun)
	{
		perror("SHM TRUNCATE");
		exit(EXIT_FAILURE);
	}

	int *count = (int *)mmap(NULL , sizeof(int) , PROT_READ | PROT_WRITE , MAP_SHARED ,fd, 0 );
//	if ( MAP_FAILED == *count)
//	{
//		perror("MAP_FAILED");
//		exit(EXIT_FAILURE);
///	}

	*count=0;

	while (1)
	{
		(*count)++;
		printf("SENDER count : %d\n",*count);
		sleep(2);
	}

	int unlink= shm_unlink(mem);
	{
	if (-1 == unlink)
		perror("SHM UNLINK");
		exit(EXIT_FAILURE);
	}

	return 0;
}

