/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:03:23 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/18 18:06:30 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		n;
	char	*cpy;

	n = 0;
	cpy = (char*)s;
	while (cpy[n] != '\0')
	{
		if (cpy[n] == c)
			return (&cpy[n]);
		n++;
	}
	return ((cpy[n] == c) ? &cpy[n] : NULL);
}
