#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include<sys/wait.h>

struct message
{
	long id;
	char str[100];
};


int main()
{

	key_t key = ftok("DAC", 123);
	struct message msg;

	int mqid = msgget(key, IPC_CREAT | 0666);

	//msg.id=1;

	pid_t pid;
	
	pid = fork();
	
	if(pid<0)
	{
		printf("Fork Failed");
	}
	
	if(pid==0)
	{
		printf("Enter the message that you wants to send\n");
		scanf("%s", msg.str);
		msg.id=1;
		msgsnd(mqid, &msg, sizeof(msg), 0);
	}
	else
	{
		int stat = 0;
		msgrcv(mqid, &msg, sizeof(msg), 1, 0);
		printf("Message received is: %s\n", msg.str);
		waitpid(pid,&stat,0);	
	}

	msgctl(mqid, IPC_RMID, 0);
	return 0;
}

