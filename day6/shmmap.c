#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main()
{
	int fd;
	char ip[100];
       pid_t pid;
       
       pid = fork();

	if(pid<0)
	{
		printf("fork has failed!");
	}
	
	if(pid==0)
	{
		fd = open("test.txt", O_RDWR | O_CREAT, 0600);
		printf("\nEnter a String: ");
		scanf("%s",ip);
		write(fd, &ip, sizeof(ip));
		char *buf = mmap(0, sizeof(100), PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0);
		memcpy(buf, ip ,sizeof(100));
       		munmap(buf, sizeof(100));
       		close(fd);
	}
	else
	{
		int stat = 0;
		waitpid(pid,&stat,0);
		fd = open("test.txt", O_RDONLY);

		char *buf = mmap(0, sizeof(100), PROT_READ , MAP_SHARED,fd, 0);
		
		printf("%s", buf);
		
       		munmap(buf, sizeof(100));
       		close(fd);
	}


return 0;
}
