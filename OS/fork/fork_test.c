#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	char *message;	
	int n;
	printf("fork programming startin\n");
	pid=fork();
	switch(pid)
	{
	case -1 : 
		perror("fork failed\n");
		break;
	case 0  :
		message="This is the child";
		n=5;
		break;
	default :
			message="This is parent";
			n=3;
		break;
	} //switch ends

	for ( ; n > 0 ;n-- )
	{
		puts(message);
		sleep(1);
	}
	return 0;
}
