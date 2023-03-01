/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:44:14 by macastan          #+#    #+#             */
/*   Updated: 2023/02/16 11:44:27 by macastan         ###   ########.fr       */
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

void	received(int sinal, siginfo_t *info, void *other)
{
	(void)info;
	(void)other;
	if (sinal == SIGUSR1)
		ft_printf("Message received.\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;
	int					pid_s;

	i = 0;
	if (argc != 3)
		return (ft_printf("Please, check the input.\n"));
	if (argc == 3)
	{
		sa.sa_sigaction = &received;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_SIGINFO;
		pid_s = ft_atoi(argv[1]);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_printf("Error.\n");
		while (argv[2][i] != '\0')
		{
			send_char(pid_s, argv[2][i]);
			i++;
		}
		send_char(pid_s, '\n');
		send_char(pid_s, '\0');
	}
	while (1)
		pause ();
	return (0);
}
