/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:27:22 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/06 08:13:17 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	decrypt_char(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = decrypt_char;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
