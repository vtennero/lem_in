/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:30:23 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/13 17:47:12 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist)
	{
		while (lst && f)
		{
			newlist = f(lst);
			lst = lst->next;
		}
	}
	return (newlist);
}
