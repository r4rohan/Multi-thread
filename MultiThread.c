#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int average, minimum, maximum,n;
void *avg(void *arg);
void *min(void *arg);
void *max(void *arg);

int arr[100];

int main()
{
	printf("\n How many number do you want to enter :");
	scanf("%d",&n);
	printf("\n");
	pthread_t thread1,thread2,thread3;
	int check1,check2,check3,i;

	for(i=0;i<n;i++)
	{
		printf("Enter no. %d : ",i+1);
		scanf("%d",&arr[i]);
		printf("\n");
	}

	check1 = pthread_create(&thread1,NULL,avg,(void*)arr);
	check2 = pthread_create(&thread2,NULL,min,(void*)arr);
	check3 = pthread_create(&thread3,NULL,max,(void*)arr);

	if((check1 == 0) && (check2 == 0) && (check3 == 0))
	{
		printf("\n All Threads are Created Successfully\n");
	}
	else
	{
		printf("\n Error!!!!!");
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	printf("\n Inside Parent Thread");
	printf("\n Average is : %d",average);
	printf("\n Minimum is : %d",minimum);
	printf("\n Maximum is : %d",maximum);
	printf("\n");
	return 0;
}

void *avg(void *arg)
{
	int s = 0,i;
	for(i=0;i<n;i++)
	{
		s = s + arr[i];
	}
	average = (s/n);
	return NULL;
}

void *min(void *arg)
{
	int i;
	minimum = arr[0];
	for(i=1;i<n;i++)
	{
		if(minimum > arr[i])
		{
			minimum = arr[i];
		}
	}
	return NULL;
}

void *max(void *arg)
{
	int i;
	maximum = arr[0];
	for(i=1;i<n;i++)
	{
		if(maximum < arr[i])
		{
			maximum = arr[i];
		}
	}
	return NULL;
}
