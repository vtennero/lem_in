/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 14:17:25 by vtennero          #+#    #+#             */
/*   Updated: 2017/07/23 20:42:39 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoisign(int sign, long n)
{
	if (sign == -1)
	{
		if (n - 9223372036854775807 > 0)
			return (0);
		else
			return (-(int)n);
	}
	else
	{
		if (n - 9223372036854775807 > 0)
			return (-1);
		else
			return ((int)n);
	}
	return (197);
}

int				ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		sign;

	n = 0;
	i = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] < 58)
	{
		sign = -1;
		i++;
	}
	if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] < 58)
	{
		n = 10 * n + str[i] - '0';
		i++;
	}
	return (ft_atoisign(sign, n));
}
