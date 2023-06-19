/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:04:21 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/16 23:38:57 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write (1, &c, 1);
	}
}

void	ft_print_messig(int sig, siginfo_t *info, void *ptr)
{
	static int				bit;
	static unsigned char	byte = 0xFF;

	(void)ptr;
	if (sig == SIGUSR1)
		byte |= 128 >> bit;
	else
		byte ^= 128 >> bit;
	if (++bit == 8)
	{
		if (byte == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, &byte, 1);
		byte = 0xFF;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_print_messig;
	sa.sa_flags = SA_SIGINFO;
	write(1, "pid: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
