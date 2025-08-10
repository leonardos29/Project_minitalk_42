/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:26:32 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/07/28 19:58:37 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	iswhite_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		||c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	while (iswhite_space(*nptr))
	{
		nptr++;
	}
	sign = 1;
	if ((*nptr == '+') || (*nptr == '-'))
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
