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
	
		int fd;
		char buf[50];
		int prn, phone;

			fd = open("mypipe", O_RDONLY);
			read(fd, buf, sizeof(buf));
			printf("%s\n", buf);
			read(fd, &prn, sizeof(prn));
			printf("%d\n", prn);
			read(fd, &phone, sizeof(phone));
			printf("%d\n", phone);
			close(fd);
	return 0;
}
