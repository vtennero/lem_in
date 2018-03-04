/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:03:23 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/18 17:41:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*cpy;
	int		i;

	i = 0;
	n = 0;
	cpy = (char*)s;
	while (cpy[n] != '\0')
	{
		if (cpy[n] == c)
			i = n;
		n++;
	}
	if (c == '\0')
		return (&cpy[n]);
	return ((cpy[i] == c) ? &cpy[i] : NULL);
}
