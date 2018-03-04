/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 19:58:59 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/08 19:16:22 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	i = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size > (ldst + 1))
	{
		while (i < (size - ldst - 1) && (i < lsrc))
		{
			dst[ldst + i] = src[i];
			i++;
		}
		dst[ldst + i] = '\0';
	}
	if (size >= ldst)
		return (ldst + lsrc);
	return (lsrc + size);
}
