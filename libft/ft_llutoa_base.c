/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:22:15 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/17 15:22:26 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llutoa_base(unsigned long long n, const char *base)
{
	char					*str;
	int						baselen;
	int						i;
	unsigned long long		nc;

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
