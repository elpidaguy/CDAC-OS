#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main()
{

	if(mkfifo("mypipe", 0600) < 0)
	{
		printf("Error");
		return -1;
	}
	
		int fd;
		pid_t pid;
		char buf[50];
		int stat = 0;
           
		pid = fork();
		if (pid < 0) {
           		printf("Fork failed");
           		return -1;
		}

		if (pid == 0) {
		
			fd = open("mypipe", O_WRONLY);
			printf("\nEnter a String: \n");
			scanf("%s", buf);
			write(fd, buf, sizeof(buf));
			close(fd);
			
           	} else {
           		//sleep(10);
			//waitpid(pid, &stat, 0);
			fd = open("mypipe", O_RDONLY);
			read(fd, buf, sizeof(buf));
			printf("%s", buf);
			close(fd);

		}
	return 0;
}
