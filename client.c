/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:44:20 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/30 10:14:24 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int pid, char c)
{
	int	i;
	int	return_kill;

	i = 8;
	while (i--)
	{
		if (c & 1 << i)
			return_kill = kill(pid, SIGUSR2);
		else
			return_kill = kill(pid, SIGUSR1);
		if (return_kill == -1)
		{
			write(1, "wrong pid", 9);
			exit(1);
		}
		usleep(350);
	}
}

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int					i;

	i = 0;
	if (ac == 3)
	{
		if (check(av[1]) || ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > INT_MAX)
		{
			write(1, "WRONG PID\n", 10);
			exit(EXIT_FAILURE);
		}
		while (av[2][i])
		{
			send_signal(atoi(av[1]), av[2][i]);
			i++;
		}
		send_signal (atoi(av[1]), '\0');
	}
	else
		write(2, "not 2 arguements\n", 18);
	return (1);
}
