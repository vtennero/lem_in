/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:58:58 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/18 19:43:39 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*start;
	char	*to_find;

	if (!*big && !*little)
		return ((char*)big);
	while (*big)
	{
		start = (char*)big;
		to_find = (char*)little;
		while (*big && *to_find && (*big == *to_find))
		{
			big++;
			to_find++;
		}
		if (!(*to_find))
			return (start);
		big = start + 1;
	}
	return (NULL);
}
