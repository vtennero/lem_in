/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:13:08 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/25 18:45:00 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*ptr;

	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] != ptr[i])
			return (str[i] - ptr[i]);
		i++;
	}
	return (0);
}
