#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

 void* thread(void* data)
	{
	printf("RTC thread:\n");
//	printf("DATA : %s\n",data);
	char *k=data;
//	printf("K : %s\n",k);
	int n,sum=atol(data);
	while(*k!= '\0')
	{
		if(*k==',')
		{	
			n=atol(k+1);
			sum=sum+n;
		}
		k++;
	
	}
	printf("The Sum is %d\n",sum);
}

 int main()
	{

	pthread_t id;
	printf("before thread:\n");
	char *input;
	printf("Enter numbers to add seperated by coma','\n");
	scanf("%s",input);
	pthread_create(&id,NULL,thread,input);
//	thread(input);
	printf("after thread:\n");
	pthread_join(id,NULL);
	return 0;
	}
