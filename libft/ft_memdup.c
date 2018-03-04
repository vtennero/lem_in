/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:42:11 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/19 13:42:12 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, size_t n)
{
	void	*mem;

	if (s && (mem = malloc(n)))
		return (ft_memcpy(malloc(n), s, n));
	return (NULL);
}
