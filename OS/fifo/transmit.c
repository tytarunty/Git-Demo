#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define buf_size 10

int main()
{
    int fds,fdr_1,i,sum=0;
    int buffer[buf_size]={10,20};
    fds=open("fifo",O_WRONLY);
    fdr_1=open("fifo_1",O_RDONLY);
    if((-1==fds) | (-1==fdr_1))
    {
        printf("error occured\n");
    }
    write(fds,buffer,buf_size);
    read(fdr_1,&sum,sizeof(int));
    printf("recive from reciver: %d\n",sum);
    close(fds);
    close(fdr_1);
    return 0;
}
