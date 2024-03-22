
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// volatile int t_signal = 0;
void res_handler(int sig)
{
	if(sig)
	{
		write(1, "recieved\n",strlen("recieved\n"));
		
		}
}
// void sigusr_handler(int sig, siginfo_t *info, void *context)
// {
// 	(void)context;

// 	if(sig == SIGUSR1 && !t_signal)
// 		write(1, "OK ooooooo", 11);
// 	else
// 		t_signal ++;

// }
void send_signal(int pid, char c)
{
	int i = 8;

	while(i--)
	{
		if (c & 1 << i) 
		{
			kill(pid,SIGUSR2);// printf("true\n");
		}
		else
		{
			kill(pid,SIGUSR1);
			// printf("false\n");
		}
			usleep(350);
	}
	// printf("%c\n", c);
}

int main(int ac, char **av)
{
	int i = 0;
	struct sigaction sa1;
	sa1.sa_handler = &res_handler;
	sigaction(SIGUSR1, &sa1, NULL);
	if (ac == 3)
	{
		while(av[2][i])
		{
			send_signal(atoi(av[1]),av[2][i]);
			i++;
		}
		send_signal(atoi(av[1]),'\0');
	}
}



