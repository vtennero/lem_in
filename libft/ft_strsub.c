/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:47:16 by vtennero          #+#    #+#             */
/*   Updated: 2017/07/08 17:27:10 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	str = NULL;
	if (s)
	{
		str = malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		while (i < start)
			i++;
		while (j < len)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
	}
	return (str);
}
