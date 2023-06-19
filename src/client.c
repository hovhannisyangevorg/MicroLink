/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:04:19 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/19 16:55:27 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_byte(unsigned char byte, int pid)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if ((byte & (128 >> i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		++i;
		if (i == 8)
			break;
	}
}

void	ft_msg_handler(char *msg, int pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		ft_send_byte(msg[i], pid);
	ft_send_byte(msg[i], pid);
}

void	ft_print_message(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message sent\n", ft_strlen("Message sent\n"));
	}
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
	signal(SIGUSR1, ft_print_message);
	pid = ft_atoi(av[1]);
	msg = av[2];
	ft_msg_handler(msg, pid);

	return (0);
}
