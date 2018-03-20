/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:13:08 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/25 16:32:17 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;
	size_t	lstr;
	size_t	lstr2;

	i = 0;
	str = (char*)dst;
	str2 = (char*)src;
	lstr = (size_t)ft_strlen(str);
	lstr2 = (size_t)ft_strlen(str2);
	while (i < n && i <= lstr && i <= lstr2)
	// while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (str);
}
