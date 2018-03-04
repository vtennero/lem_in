/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:02:26 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/20 17:01:46 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long n, const char *base)
{
	char	*str;
	int		baselen;
	int		i;
	long	nc;
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
