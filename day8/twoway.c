/*
Write a program to allow two way communication between process using shared memory.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
	key_t key = ftok("DAC2", 1);

	int shared_id = shmget(key, 1024, IPC_CREAT | 0666);

	char *buf = shmat(shared_id, NULL, 0);

	pid_t pid = fork();
	
	if(pid < 0)
	{
		printf("fork Failed");
	}
	
	if(pid==0)
	{
		printf("CHILD::Enter your name\n");
		scanf("%s", buf);
		
		sleep(13);
		printf("CHILD::User entered: %s\n", buf);
	}
	else
	{
//		int stat=0;
//		waitpid(pid,&stat,0);

		sleep(5);
		printf("PARENT::User entered: %s\n", buf);
		
		sleep(7);
		printf("PARENT::Enter your name\n");
		scanf("%s", buf);
	}

	shmdt(buf);

	
	shmctl(shared_id, IPC_RMID, NULL);

	return 0;
}


