/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:57:32 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/20 16:57:34 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ltoa(long n)
{
	int		neg;
	int		i;
	char	*str;

	neg = (n < 0) ? 1 : 0;
	i = ft_longlen((n));
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	if (str)
	{
		while (i > 0)
		{
			str[--i] = ft_abs(n % 10) + 48;
			n /= 10;
		}
		if (neg == 1)
			str[0] = '-';
	}
	return (str);
}
