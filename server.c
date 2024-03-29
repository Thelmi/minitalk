/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:45:03 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/29 15:15:27 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	c;
	char		cp;

	if (!i)
	{
		i = 8;
		c = 0;
	}
	if (sig == SIGUSR2)
		c = c | 1 << (i - 1);
	if (i == 1)
	{
		cp = c + 0;
		write(1, &cp, 1);
		if (c == '\0')
			kill(info -> si_pid, SIGUSR1);
	}
	i--;
}

void	ft_putnbr(int n)
{
	char	digit;

	if (n > 9)
		putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
