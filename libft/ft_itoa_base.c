/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:02:26 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/02 22:46:05 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, const char *base)
{
	char	*str;
	int		baselen;
	int		i;
	int		nc;
	int		neg;

	if (!base)
		return (NULL);
	neg = (n < 0) ? 1 : 0;
	i = 1 + neg;
	baselen = ft_strlen(base);
	nc = n;
	while (nc /= baselen)
		++i;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = base[ft_abs(n % baselen)];
		n /= baselen;
	}
	str[i] = (neg == 1) ? '-' : str[i];
	return (str);
}
