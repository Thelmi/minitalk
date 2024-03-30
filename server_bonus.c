/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:17:04 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/30 09:17:07 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	c;
	char		cp;

	(void) context;
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

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
