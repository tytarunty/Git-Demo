#include <sys/types.h>  
#include <sys/socket.h>
#include <stdlib.h>
#include <error.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int SS,CS;

struct sockaddr_in saddr;
struct sockaddr_in caddr;
unsigned char buff[1024];

int main()
{
	SS=socket(AF_INET, SOCK_STREAM, 0);
	if ( -1 == CS )
	{
		perror("SOCKET ERROR");
		exit(EXIT_FAILURE);
	}

	saddr.sin_family=AF_INET;
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	saddr.sin_port=htons(5678);

	int bindv = bind(SS,(struct sockaddr *)&saddr,sizeof(saddr));
	if( -1 == bindv )
	{
		perror("BIND ERROR");
		exit(EXIT_FAILURE);
	}
	printf("BIND COMPLETED\n");

	int listenv=listen(SS,2);
	if ( -1 == listenv )
	{
		perror("LISTEN ERROR");
		exit(EXIT_FAILURE);
	}
	printf("LISTEN DONE\n");

	socklen_t csize;
	CS=accept(SS,(struct sockaddr *)&caddr,&csize);
	if ( -1 == CS )
	{
		perror("ACCEPT");
		exit(EXIT_FAILURE);
	}
	printf("ACCEPT DONE : %d\n", CS);
	read(CS,buff,1024);
	printf("client sent :%s\n",buff);
	write(CS,"Msg form server\n",16);
	close(SS);
	close(CS);
	return 0;
}
