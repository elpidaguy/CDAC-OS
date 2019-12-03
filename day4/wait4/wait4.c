/*4. Create 5 processes from a common parent and ensure that the parent
terminates after cleaning all the terminated children using waitpid().
The waitpid() must be called after all the children are created
and the parent has completed its work real work,if any; in addition, you must
compile 5 different program files to in children processes to generate their
respective object files ; the parent process must use waitpid() to collect the
termination status of children processes – based on the exit code information
generated by children processes, link all the object files to
generate the final, linked program/application. In addition, the generated
binary executable must be loaded in a new process, if the linking is
successful */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main() 
{ 
    int pid, pid1, pid2, pid3, pid4, pid5; 
    int status1,status2,status3,status4,status5 = 0;
    pid = fork(); 

    if (pid == 0) {
        sleep(10);
        printf("child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
        execl("/usr/bin/gcc","gcc","-c","c5.c",NULL);
    }
    else{
        //sleep(5);
        pid1 = fork(); 
        if (pid1 == 0) { 
            sleep(15); 
            printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
            execl("/usr/bin/gcc","gcc","-c","c4.c",NULL);
        } 
        else {
            pid2 = fork(); 
            if (pid2 == 0) {
            	sleep(20);
                printf("child[3] --> pid = %d and ppid = %d\n", getpid(), getppid());
                execl("/usr/bin/gcc","gcc","-c","c3.c",NULL);
            }
            else {
                pid3 = fork(); 
		    if (pid3 == 0) {
		    	sleep(25);
		        printf("child[4] --> pid = %d and ppid = %d\n", getpid(), getppid());
		        execl("/usr/bin/gcc","gcc","-c","c1.c",NULL);
		    } 
		    else {
				pid4 = fork(); 
				    if (pid4 == 0) {
				    	sleep(30); 
					printf("child[5] --> pid = %d and ppid = %d\n", getpid(), getppid());
					//execl("/usr/bin/gcc","gcc","-c","c1.c",NULL);
					execl("/usr/bin/gcc","gcc", "c5.o" ,"c4.o", "c3.o", "c2.o", "c1.o",NULL);
					//execlp("/home/dac/Desktop/8393/OSC/day4/wait4/a.out","./a.out",NULL);
				    } 
				    else {
					pid5 = fork(); 
				    	if (pid5 == 0) {
				    		sleep(40); 
						printf("child[6] --> pid = %d and ppid = %d\n", getpid(), getppid());
						
						//execl("/usr/bin/gcc","gcc", "c5.o" ,"c4.o", "c3.o", "c2.o", "c1.o",NULL);
						execlp("/home/dac/Desktop/8393/OSC/day4/wait4/a.out","a.out",NULL);
				    	} 
				    	else {
						printf("parent --> pid = %d\n", getpid());
				   	}
				    }
		    }
            }
        }
        
        	waitpid(pid, &status1, 0);
		if (WIFEXITED(status1))
		{
			printf("Child has terminated normally\n");
		}
		else if (WIFSIGNALED(status1))
		{	
			//if(WIFSTOPPED(status1))
				printf("Child has been killed due to signal: %d.\n", WTERMSIG(status1));
		}
		waitpid(pid1, &status2, 0);
		if (WIFEXITED(status2))
		{
			printf("Child has terminated normally\n");
		}
		else if (WIFSIGNALED(status2))
		{	
			//if(WIFSTOPPED(status2))
				printf("Child has been killed due to signal: %d.\n", WTERMSIG(status2));
		}
		waitpid(pid2, &status3, 0);
		if (WIFEXITED(status3))
		{
			printf("Child has terminated normally\n");
		}
		else if (WIFSIGNALED(status3))
		{	
			//if(WIFSTOPPED(status3))
				printf("Child has been killed due to signal: %d.\n", WTERMSIG(status3));
		}
		waitpid(pid3, &status4, 0);
		if (WIFEXITED(status4))
		{
			printf("Child has terminated normally\n");
		}
		else if (WIFSIGNALED(status4))
		{	
			//if(WIFSTOPPED(status4))
				printf("Child has been killed due to signal: %d.\n", WTERMSIG(status4));
		}
		waitpid(pid4, &status5, 0);
	    	if (WIFEXITED(status5))
		{
			printf("Child has terminated normally\n");
		}
		else if (WIFSIGNALED(status5))
		{	
			//if(WIFSTOPPED(status5))
				printf("Child has been killed due to signal: %d.\n", WTERMSIG(status5));
		}
    }
    return 0; 
}