/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:06 by macastan          #+#    #+#             */
/*   Updated: 2023/02/15 15:04:48 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

void	print_msg(int sinal)
{
	static int	c;
	static int	bit;

	if (sinal == SIGUSR2)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Please, check the input.\n");
		return (0);
	}
	ft_printf("Here's your PID: %d\n", pid);
	signal(SIGUSR1, print_msg);
	signal(SIGUSR2, print_msg);
	while (1)
		pause();
	return (0);
}
