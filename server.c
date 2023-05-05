/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:04:21 by gehovhan          #+#    #+#             */
/*   Updated: 2023/05/05 16:34:47 by gehovhan         ###   ########.fr       */
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

void	get_pid(int sig, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	byte;

	i = 0;
	byte = 0;
	(void)context;
	if (sig == SIGUSR1)
		byte |= 1;
	if (++i == 8)
	{
		write(1, &byte, 1);
		kill(info->si_pid, SIGUSR1);
		usleep(100);
		byte = 0;
		i = 0;
	}
	else
		byte <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_pid;
	write(1, "pid: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
