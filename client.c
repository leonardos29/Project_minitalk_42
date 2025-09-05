/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:27:29 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/05 03:30:12 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	encrypt_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		while (!g_ack)
			pause();
		i++;
	}
}

void	sending_char(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		encrypt_char(str[i], pid);
		i++;
	}
	encrypt_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Use Only 3 arguments please: ./client <PID> <MESSAGE>\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr("PID inválido\n");
		exit(1);
	}
	signal(SIGUSR2, ack_handler);
	sending_char(argv[2], pid);
}
