/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:41:51 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/19 13:41:53 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *lst, t_list *elem)
{
	if (lst)
	{
		lst = ft_lstend(lst);
		lst->next = elem;
		if (elem)
			elem->parent = lst;
	}
	return (elem);
}
