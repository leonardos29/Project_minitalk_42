/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:26:45 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/07/29 01:39:50 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

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