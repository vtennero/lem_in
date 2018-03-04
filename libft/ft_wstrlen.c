/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:30:06 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/28 17:32:17 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int	len;

	len = 0;
	if (wstr)
	{
		while (*wstr)
		{
			len += ft_wcharlen(*wstr);
			if (ft_wcharlen(*wstr) == 0)
			{
				return (-1);
			}
			wstr++;
		}
	}
	return (len);
}
