/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:26:45 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/06 08:11:50 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <asm-generic/siginfo.h>
# include <sys/types.h>
# include <asm-generic/signal-defs.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_ptr_to_hex(void *ptr);
size_t	count_len_base(long n, unsigned int base);
int		ft_itoa(int n);
int		ft_utoa(unsigned int n);
int		ft_to_hex(unsigned long n, char c);
int		ft_atoi(const char *nptr);
#endif