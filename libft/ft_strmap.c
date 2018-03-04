/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:45:20 by vtennero          #+#    #+#             */
/*   Updated: 2017/07/08 13:19:54 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		l;
	int		i;

	i = 0;
	str = NULL;
	if (s && f)
	{
		l = ft_strlen(s);
		str = malloc(sizeof(char) * l + 1);
		if (!str)
			return (NULL);
		while (i < l)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
