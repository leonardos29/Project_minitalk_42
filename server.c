/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:27:22 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/07/29 03:52:42 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	is_buffer_overflow(int i, char *str)
{
	if (i >= BUFFER_SIZE - 1)
	{
		str[i] = '\0';
		ft_printf("%s", str);
		return (1);
	}
	return (0);
}

void	decrypt_char(int sig)
{
	static int	bit = 0;
	static char	str[BUFFER_SIZE];
	static int	i = 0;

	if (sig == SIGUSR1)
		str[i] |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (str[i] == '\0')
		{
			ft_printf("%s\n", str);
			i = 0;
		}
		else
		{
			i++;
			if (is_buffer_overflow(i, str))
				i = 0;
		}
		bit = 0;
		str[i] = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	signal(SIGUSR1, decrypt_char);
	signal(SIGUSR2, decrypt_char);
	while (1)
		pause();
}
