/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 02:55:27 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/05 03:00:41 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

static void	to_hex_str(char *str, size_t pos, unsigned long n, char c)
{
	const char	*hex;

	if (c == 'l')
		hex = "0123456789abcdef";
	else if (c == 'u')
		hex = "0123456789ABCDEF";
	else
		return ;
	str[pos] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (n != 0)
	{
		str[--pos] = hex[n % 16];
		n /= 16;
	}
}

int	ft_to_hex(unsigned long n, char c)
{
	size_t	s_len;
	char	*str;

	s_len = count_len_base(n, 16);
	str = malloc(s_len + 1);
	if (!str)
		return (0);
	to_hex_str(str, s_len, n, c);
	ft_putstr(str);
	free(str);
	return ((int)s_len);
}

int	ft_ptr_to_hex(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_to_hex((unsigned long)ptr, 'l');
	return (len);
}
