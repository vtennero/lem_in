/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:56:39 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/14 16:56:41 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*free_node(t_node *node)
{
	free(node->name);
	node->name = NULL;
	free(node);
	node = NULL;
	return (0);
}

t_node			*create_node(int x, int y, char *name)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		if (!(new_node->name = ft_strdup(name)))
			return (free_node(new_node));
		new_node->visited = 0;
		new_node->coord.x = x;
		new_node->coord.y = y;
		new_node->next = NULL;
		ft_printf("new node: %s x = %d y = %d\n", new_node->name, new_node->coord.x, new_node->coord.y);
	}
	return (new_node);
}

t_node			*pushback_node(t_node *start, t_node *new)
{
	t_node		*tmp;

	tmp = NULL;
	if (!start)
		return (new);
	if (new)
	{
		tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (start);
}
/*
t_node			*build_graph(t_lem *params)
{
	t_node		*start;
	t_node		*new;
	int			i;
	int			j;

	i = 0;
	start = NULL;
	new = NULL;
	if (!global->shape)
		return (0);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (global->shape[i][j] == '*')
			{
				new = create_shape(j, i);
				start = pushback_node(start, new);
			}
			j++;
		}
		i++;
	}
	return (start);
}*/
