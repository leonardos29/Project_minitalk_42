/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:26:06 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/08/10 16:01:10 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

size_t	count_len_base(long n, unsigned int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

static void	ft_into_to_str(char *str, size_t position, long n)
{
	str[position] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		str[--position] = (n % 10) + '0';
		n /= 10;
	}
}

int	ft_itoa(int n)
{
	char	*str;
	long	ln;
	size_t	s_len;

	ln = n;
	s_len = count_len_base(ln, 10);
	str = malloc(s_len + 1);
	if (!str)
		return (0);
	ft_into_to_str(str, s_len, ln);
	ft_putstr(str);
	free(str);
	return ((int)s_len);
}

int	ft_utoa(unsigned int n)
{
	char			*str;
	size_t			s_len;
	unsigned long	ln;

	ln = n;
	s_len = count_len_base(ln, 10);
	str = malloc(s_len + 1);
	if (!str)
		return (0);
	ft_into_to_str(str, s_len, ln);
	ft_putstr(str);
	free(str);
	return ((int)s_len);
}
