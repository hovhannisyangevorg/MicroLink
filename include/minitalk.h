/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:52:43 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/19 17:35:15 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// path clent.c
void	ft_print_message(int sig);
void	ft_msg_handler(char *msg, int pid);
void	ft_send_byte(unsigned char byte, int pid);

// path utils.c
int	ft_strlen(const char *s);
int	ft_atoi(const char *nptr);

// path server.c
void	ft_print_messig(int sig, siginfo_t *info, void *ptr);
void	ft_putnbr(int n);

#endif