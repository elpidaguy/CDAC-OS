#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<unistd.h>


int a = 1;
sem_t sem;
int val = 0;

void* inc()
{	
	sem_wait(&sem);
	sem_getvalue(&sem, &val);
	printf("Semaphore Decreased: %d",val);
//	int temp = a;
//	++a;
//	printf("\nPrevious value= %d, New value= %d", temp, a);
//	printf("\n");
	
	for(int i=0;i<=50;i++)
	{
		int temp = a;
		++a;
		printf("\nPrevious value= %d, New value= %d", temp, a);
		printf("\n");
	}

	sem_post(&sem);
	sem_getvalue(&sem, &val);
	printf("Semaphore Closed: %d",val);

	return NULL;
}

int main()
{
	int tid1,tid2;
	int val = 0;
	pthread_t newThread1,newThread2;
	
	sem = *sem_open("mylock", O_CREAT, 0600, 1);

	//sem_getvalue(&sem, &val);
	
	//sleep(1);
	tid1 = pthread_create(&newThread1, NULL, inc, NULL);
	
	//sleep(5);
	tid2 = pthread_create(&newThread2, NULL, inc, NULL);
	
	pthread_join(newThread1, NULL);
	pthread_join(newThread2, NULL);
	
	sem_unlink("mylock");

return 0;
}
