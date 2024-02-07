#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define buf_size 10
int add(int a[],int b);
int main()
{
    int fdr,fds_1,i,sum=0;
    int buffer[buf_size];
     for(i=0;i<2;i++)
    {
    printf("before=%d\n",buffer[i]);
    }
    fdr=open("fifo",O_RDONLY);
    fds_1=open("fifo_1",O_WRONLY);
     if((-1==fdr) | (-1==fds_1))
    {
        printf("error occured\n");
    }
    read(fdr,buffer,buf_size);
    sum=add(buffer,2);
    for(i=0;i<2;i++)
    {
    printf("after recv:%d\n",buffer[i]);
    }
    printf("sum=%d\n",sum);
   write(fds_1,&sum,sizeof(int));
    close(fdr);
    close(fds_1);
    return 0;
}


int add(int a[],int b)
{
    int sum=0,i;
    for(i=0;i<b;i++)
    {
        sum+=a[i];
    }
    return sum;
}
