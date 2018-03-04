/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:31:14 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/07 19:31:20 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strtrimempty(void)
{
	char	*str;

	str = malloc(1);
	if (str)
	{
		str[0] = '\0';
		return (str);
	}
	return (NULL);
}

static char		*ft_trimcpy(char *dst, const char *src, size_t len, int start)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

static int		ft_strtrimc2(char const *s, int n)
{
	int	i;
	int	p;

	i = 0;
	p = n - 1;
	while (s[p] == ' ' || s[p] == '\t' || s[p] == '\n')
	{
		i++;
		p--;
	}
	return (i);
}

static int		ft_strtrimc1(char const *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int			a;
	int			b;
	int			i;

	i = 0;
	if (s)
	{
		a = ft_strtrimc1(s);
		b = ft_strtrimc2(s, ft_strlen(s));
		if (!ft_strnew((size_t)((int)ft_strlen(s) - a - b)))
		{
			if (((int)ft_strlen(s) - a - b) <= 0 || ft_strlen(s) == 0)
				return (ft_strtrimempty());
			else
				return (NULL);
		}
		else if (((int)ft_strlen(s) - a - b) <= 0 || ft_strlen(s) == 0)
		{
			return (ft_strtrimempty());
		}
		else
			return (ft_trimcpy(ft_strnew((size_t)((int)ft_strlen(s) - \
								a - b)), s, (int)ft_strlen(s) - a - b, a));
	}
	return (0);
}
