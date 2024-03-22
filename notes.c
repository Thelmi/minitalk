// signal are one of the simplist ways that you can interact with a process on Mac os, linux or any unix style operating system.

// When signal is raised it can work, ignored, connected to another action

// Functions time 
//******************

// getpid():  returns the process ID of the calling process.

    // kill(): send a signal to a process, takes two argments.
	// (Target process ID, signal number or sigterm), returns 0 on success -1 
	// on error. just for testing that a proccess exist (ues 0 (sig num)) */

// signal(): registering a handler function to run whenever the specified 
// signal is recieved

/* sigaction(): system call that allows you to actully change the action for a 
specific signal, but first you hace to initialize the signal set. either to
exclude all signals or to be full which means include all signals.
*/

// sigemptyset() function initializes a signal set to be empty.

// #include <unistd.h>
// #include <stdio.h>

// 
// int main()
// {
// 	printf("%d", getpid()); // displaying PID number
// }
// **************

// *******************
// #include <stdio.h>
// #include <unistd.h>
// #include <signal.h>
// #include <stdio.h>

// void handler(int num){
// 	write(STDOUT_FILENO, "I won't die\n", 13);
// }
// int main()
// {
// 	signal(SIGINT, handler);
// 	while (1)
// 	{
// 		printf("wasting your cycles. %d/n", getpid());
// 		sleep(1);
// 	}

// }
// ******************* 
// some signals simple practices.
// part1
// #include <stdio.h>
// #include <unistd.h>
// #include <signal.h>
// #include <stdio.h>

// void my_handler(int signo)
// {
// 	printf("Signal Caught is %d",signo);
// }
//  !! this is referred as the signal handler. This will be cancelled when the below code gets running.
// int main ()
// {
// 	// (void)signal(SIGINT ,my_handler);
// 	// we are trying to ignore the CTRL + C
// 	while(1)
// 	{
// 		printf("Hello World \n");
// 		sleep(10);
// 	}
// }
// **************
// part 2
// #include <stdio.h>
// #include <unistd.h>
// #include <signal.h>
// #include <stdio.h>
// int main (void)
// {
// 	(void) signal (SIGINT, SIG_IGN); // disclaimer some signals cannot be ignored such as sigkill
// 	while  (1)
// 	{
// 		printf("\n Don't sleep")
// 	}
// }
// ***********
// some notes
//  what is signal?
/*
A signal represents some sort of an event that's delivered to a process
by the kernal the signal serves as notification that something has happened 
usually something external to the process that the process may want to
respond to. A process may want to respond to a process chooses what it wants
to do when the signal arrives by providing a function calle da signal handler
and then installing the handler
*/   
// What are te different ways in which a process responds to a signal?
// ignoring the signal, handling the signal, or performing some default action

// The process can pass values 1 or 0 instead of function address  

// bit shifts; 
// 010000001  = 01000000

// 7
// 010000001  
// 100000000      false
// 6
// 010000001  
// 010000000   true
// 5
// 010000001  
// 001000000   false
// 4
// 010000001   
// 000100000	false
// 3
// 010000001  
// 000010000   false
// 2
// 010000001  
// 000001000    false
// 1
// 010000001
// 000000010    false
// 0
// 010000001
// 000000001     true

// 0
// 00000000         false   00000000
// 00000000                   

// 1
// 00000000         |    true  01000000
// 00000001            

// 2
// 00000000
// 00000000         |    false 001000000
// 3
// 00000000        |     false  000100000

// 4
// 00000000                     00010000

// 5
// 00000000                     00100000

// 6
// 00000000                     01000000
// 00000000        

// 7 00000000					 10000001	
//   00000001

// sigaction
// ************

// sigaction();
// first paramater = signal type.
// second paramater = sign_IGN | SIG_DFL | address sa_handler | sa_musk | sa_flags
//  sa_musk = "set signals to block";
// sa_falgs
