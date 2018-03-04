/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:58:07 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/20 16:58:29 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lutoa(unsigned long n)
{
	int		i;
	char	*str;

	i = ft_ulonglen((n));
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	if (str)
	{
		while (i > 0)
		{
			str[--i] = ft_abs(n % 10) + 48;
			n /= 10;
		}
	}
	return (str);
}
