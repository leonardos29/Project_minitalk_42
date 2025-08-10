/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:25:51 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/08/10 16:01:14 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

static int	fix_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (format == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len = ft_ptr_to_hex(va_arg(args, void *));
	else if (format == 'd')
		len = ft_itoa(va_arg(args, int));
	else if (format == 'i')
		len = ft_itoa(va_arg(args, int));
	else if (format == 'u')
		len = ft_utoa(va_arg(args, int));
	else if (format == 'x')
		len = ft_to_hex(va_arg(args, unsigned int), 'l');
	else if (format == 'X')
		len = ft_to_hex(va_arg(args, unsigned int), 'u');
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			size;

	i = 0;
	size = 0;
	va_start (args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			size += fix_format(args, format[i]);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}
