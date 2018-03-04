/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 13:48:46 by vtennero          #+#    #+#             */
/*   Updated: 2017/06/24 17:46:28 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd(45, fd);
		ft_putnbr_fd(21474, fd);
		ft_putnbr_fd(83648, fd);
	}
	else
	{
		if (nb < 0 && nb > -2147483648)
		{
			ft_putchar_fd(45, fd);
			ft_putnbr_fd(-nb, fd);
		}
		if (nb >= 10)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		if (nb < 10 && nb >= 0)
			ft_putchar_fd(nb + 48, fd);
		else
			;
	}
}
