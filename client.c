/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:44:20 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/29 15:17:51 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

static void	res_handler(int sig)
{
	if (sig)
		write (1, "recieved\n",10);
}

static void	send_signal(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(350);
	}
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	sa1;

	i = 0;
	sa1.sa_handler = &res_handler;
	sigaction(SIGUSR1, &sa1, NULL);
	if (ft_atoi(av[1]) < 0 || ft_atoi(av) > )
		write(1, "\n", 17);
	if (ac == 3)
	{
		while (av[2][i])
		{
			send_signal(atoi(av[1]), av[2][i]);
			i++;
		}
		send_signal (atoi(av[1]), '\0');
	}
	write(1, "not 2 arguements\n", 18);
}
