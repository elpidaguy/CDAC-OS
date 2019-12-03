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
		char buf[50];
		int prn, phone;

			fd = open("mypipe", O_WRONLY);
			printf("\nEnter a Name: \n");
			scanf("%s", buf);
			
			printf("\nEnter a PRN: \n");
			scanf("%d", &prn);
			
			printf("\nEnter a Phone: \n");
			scanf("%d", &phone);
			
			write(fd, buf, sizeof(buf));
			
			write(fd, &prn, sizeof(prn));
			
			write(fd, &phone, sizeof(phone));
			close(fd);
	return 0;
}
