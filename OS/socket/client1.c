#include <sys/types.h>  
#include <sys/socket.h>
#include <stdlib.h>
#include <error.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int SS,CS;

struct sockaddr_in saddr;
struct sockaddr_in caddr;
unsigned char buff[1024];

int main()
{
	CS=socket(AF_INET, SOCK_STREAM, 0);
	if ( -1 == CS )
	{
		perror("SOCKET ERROR");
		exit(EXIT_FAILURE);
	}

	saddr.sin_family=AF_INET;
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	saddr.sin_port=htons(5678);
	printf("FD client1 : %d\n",CS);
	int conn=connect(CS,(struct sockaddr *)&saddr,sizeof(saddr));
	if ( -1 == conn )
	{
		perror("CONNECT ERROR");
		exit(EXIT_FAILURE);
	}

	write(CS,"hello from client1\n",18);
	read(CS,buff,1024);
	printf("server sent :%s\n",buff);
	close(SS);
	close(CS);
	return 0;
}
