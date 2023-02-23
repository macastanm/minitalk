/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:44:36 by macastan          #+#    #+#             */
/*   Updated: 2023/02/16 11:44:40 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

void	print_msg(int sinal, siginfo_t *info, void *other)
{
	static int	c;
	static int	bit;

	(void)other;
	if (sinal == SIGUSR2)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	sa.sa_sigaction = &print_msg;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_printf("Please, check the input.\n");
		return (0);
	}
	pid = getpid();
	ft_printf("Here's your PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
