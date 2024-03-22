/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:22:24 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/22 22:31:40 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int i;
	static int c; 
	// if(sig == SIGUSR2)
	// 	write(1,"true\n", 5);
	// if(sig == SIGUSR1)
	// 	write(1,"false\n",6);
	if (!i)
	{
		i = 8;
		c = 0;
	}

	if (sig == SIGUSR2)
		c = c | 1 << (i - 1);
	// else if (sig == SIGUSR1)
	// 	c = c | 0;
	if (i == 1)
	{
		// printf("(%c\n)", c);
		// fflush(NULL);
		char cp = c + 0;
		write(1, &cp, 1);
		if(c == '\0')
			kill(info -> si_pid,SIGUSR1);
	}
	i--; 
	
	
}

void putnbr(int n)
{
	if(n > 9)
		putnbr(n / 10);
	write(1, &(int){'0' + n % 10}, 1); 
}
int main()
{
	struct sigaction sa;
	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	pid_t pid = getpid();
	putnbr(pid);
	sigaction(SIGUSR1,&sa, NULL);
	sigaction(SIGUSR2,&sa, NULL);
	while(1)
	{
	// signal(SIGUSR1, sigusr_handler);
	// signal(SIGUSR2, sigusr_handler);
	
	pause();
	}
}