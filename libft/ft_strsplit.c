/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 17:50:44 by vtennero          #+#    #+#             */
/*   Updated: 2017/07/22 12:12:10 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strsplit_strdup(const char *src, char c)
{
	char	*mot;
	int		l;
	int		i;

	l = 0;
	while (src[l] && src[l] != c)
		l++;
	mot = malloc(l * sizeof(char) + 1);
	if (!mot)
		return (NULL);
	i = 0;
	while (i < l)
	{
		mot[i] = src[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

static int		ft_strsplit_nbwds(const char *str, char c)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	n = ft_strsplit_nbwds(str, c);
	tab = malloc(sizeof(char *) * n + 1);
	if (!tab)
		return (NULL);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
			tab[i++] = ft_strsplit_strdup(str, c);
		while (*str && *str != c)
			str++;
	}
	tab[i] = 0;
	return (tab);
}
