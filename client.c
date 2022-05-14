/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:27:30 by mkhalid           #+#    #+#             */
/*   Updated: 2022/05/14 14:27:34 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & 128) == 0)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		c = c << 1;
		bit++;
		usleep(800);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(1, "Please input the PID and the string to send", 43);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		write(1, "Please input a positive PID", 27);
		return (0);
	}
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, (unsigned char)argv[2][i]);
		i++;
	}
}
