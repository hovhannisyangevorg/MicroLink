/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:04:19 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/27 20:26:00 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int		g_len;

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}

void	send_byte(unsigned char byte, int pid)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (((byte >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	handler(char *msg, int pid)
{
	int	i;

	i = -1;
	while (msg[++i])
	{
		send_byte(msg[i], pid);
	}
}

void	print_message(int sig)
{
	static int	i;

	i = 0;
	(void)sig;
	if (++i == g_len)
		write(1, "Message sent\n", ft_strlen("Message sent\n"));
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		write (2, "Error: No enough parameters\n", \
		ft_strlen("Error: No enough parameters\n"));
		exit(1);
	}
	signal(SIGUSR1, print_message);
	pid = atoi(av[1]);
	msg = av[2];
	g_len = ft_strlen(msg);
	handler(msg, pid);
	return (0);
}
