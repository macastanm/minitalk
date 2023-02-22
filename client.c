/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:35:48 by macastan          #+#    #+#             */
/*   Updated: 2023/02/15 14:58:41 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

void	send_char(int pid_server, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit & 1) == 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		usleep(200);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid_s;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Please, check the input. ");
		ft_printf("It must contain the PID and one message\n");
	}
	if (argc == 3)
	{
		pid_s = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(pid_s, argv[2][i]);
			i++;
		}
		send_char(pid_s, '\0');
		send_char(pid_s, '\n');
	}
	return (0);
}
