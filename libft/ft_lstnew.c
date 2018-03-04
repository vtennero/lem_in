/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:41:41 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/19 13:41:44 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (content)
		{
			if (!(lst->content = ft_memdup(content, content_size)))
			{
				free(lst);
				return (NULL);
			}
		}
		lst->content_size = (content ? content_size : 0);
	}
	return (lst);
}
