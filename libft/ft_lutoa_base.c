/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:02:03 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/20 17:02:04 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lutoa_base(unsigned long n, const char *base)
{
	char				*str;
	int					baselen;
	int					i;
	unsigned long		nc;

	i = 1;
	if (!base)
		return (NULL);
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
	return (str);
}
