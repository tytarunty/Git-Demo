#include<stdio.h>
#include<stdlib.h>


int main(int argc,char *argv[])
{
char c;
FILE *in,*out;
	if (argc !=3)
	{
		printf("command usuage : ./copy inputfilename oouputfilename\n");
		exit(1);
	}

	in=fopen(argv[1],"r");
        if(in==NULL)
	{
	 printf("Cannot open file %s\n",argv[1]);
	 exit(1);
	}


	out=fopen(argv[2],"w");
	if(out==NULL)
        {
         printf("Cannot open file %s\n",argv[2]);
         exit(0);
        }
       

	c=fgetc(in);

 while(c != EOF)
    {
     fputc(c,out);
     c=fgetc(in);
    }

  printf("file coonversion completed\n");
  return 0;
	
}
