/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:41:27 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 17:13:22 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t c)
{
	if ((MB_CUR_MAX == 1 && c > 0xFF) || c < 0 || (c >= 0xd800 && c < 0xe000))
		return (0);
	else if ((c <= 0x7f && MB_CUR_MAX >= 1) || (c <= 0xff && MB_CUR_MAX == 1))
		return (1);
	else if (c <= 0x7ff && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 0xffff && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 0x10ffff && c >= 0xe0000 && MB_CUR_MAX >= 4)
		return (4);
	return (0);
}
