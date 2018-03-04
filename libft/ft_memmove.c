/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:13:08 by vtennero          #+#    #+#             */
/*   Updated: 2017/07/09 18:03:11 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (len)
	{
		if (dst > src)
			i = len - 1;
		else
			i = 0;
		while (len-- > 0)
		{
			s1[i] = s2[i];
			if (dst > src)
				i--;
			else
				i++;
		}
	}
	return (s1);
}
