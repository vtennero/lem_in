/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:13:08 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/25 18:02:34 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	while (i < n)
	{
		*str = *str2;
		if (*str == (unsigned char)c)
		{
			str++;
			return (str);
		}
		str++;
		str2++;
		i++;
	}
	return (NULL);
}
