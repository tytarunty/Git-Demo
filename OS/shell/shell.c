#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
  	pid_t id;
	unsigned char cmd[30],file[10];
	printf("enter the path : ");
	scanf("%s",cmd);
	id=fork();
	if(id==0)
	{
		printf("Files Present in current directory : \n");
		execl("/bin/ls","ls",cmd,NULL);
		printf("i am child\n");
	}
	else
	{
		printf("i am parent\n");
		printf("\n");
	}
	return 0;
}

