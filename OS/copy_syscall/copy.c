#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
 char block[10];
 int nread;
 int in,out;
 in = open("file.in",O_RDONLY);
 out= open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IXUSR);

 while((nread=read(in,block,10))>0)
  write(out,block,nread);
 
 exit(0);
}
