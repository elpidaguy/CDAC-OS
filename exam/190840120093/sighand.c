#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void SigInt_handle(int num)	//handler for sigint
{
	printf("\nSignal %d is Handled.", num);
}

void SigStp_handle(int num)	//handler for sigstp
{
	printf("\nSignal %d is Handled.", num);
}

void SigQuit_handle(int num)	//handler for sigquit
{
	printf("\nSignal %d is Handled.", num);
}

void SigTerm_handle(int num)	//handler for sigterm
{
	printf("\nSignal %d is Handled.", num);
}

int main()
{
	//defining structure sigaction for 4 signals
	struct sigaction sig_int,sig_stp,sig_quit,sig_term;
	
	//for SigInt
	//setting values of struc to 0
	memset(&sig_int,0, sizeof(sigaction));
	sig_int.sa_handler = SigInt_handle;
	sigaction(SIGINT, &sig_int,NULL);		//SIGINT        2       Term    Interrupt from keyboard
	
	//for SigStp
	memset(&sig_stp,0, sizeof(sigaction));
	sig_stp.sa_handler = SigStp_handle;
	sigaction(SIGTSTP, &sig_stp,NULL);		//SIGTSTP   18,20,24    Stop    Stop typed at terminal
	
	//forSigQuit
	memset(&sig_quit,0, sizeof(sigaction));
	sig_quit.sa_handler = SigQuit_handle;
	sigaction(SIGQUIT, &sig_quit,NULL);	//SIGQUIT       3       Core    Quit from keyboard
	
	//for SigTerm
	memset(&sig_term,0, sizeof(sigaction));
	sig_term.sa_handler = SigTerm_handle;
	sigaction(SIGTERM, &sig_term,NULL);	//SIGTERM      15       Term    Termination signal
	

	while(1)
	{
		printf("\nSignal Handler Listening...");
		sleep(1);
	}

return 0;
}


/*OUTPUT----------------------------------------------------------------
//first term-

dac@dac-Veriton-M200-H310:~/Desktop/190840120093$ gcc sighand.c -o sighand
dac@dac-Veriton-M200-H310:~/Desktop/190840120093$ ./sighand 

Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...

Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal 15 is Handled.
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal 2 is Handled.
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal 3 is Handled.
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal Handler Listening...
Signal 20 is Handled.
Signal Handler Listening...
Signal Handler Listening...


//second term-
dac@dac-Veriton-M200-H310:~$ kill -15 8488
dac@dac-Veriton-M200-H310:~$ kill -2 8488
dac@dac-Veriton-M200-H310:~$ kill -3 8488
dac@dac-Veriton-M200-H310:~$ kill -20 8488
dac@dac-Veriton-M200-H310:~$ kill -20 8488


*/
