/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:04:38 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:44:31 by vtennero         ###   ########.fr       */
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

t_node			*fetch_node(t_node *node, char *name)
{
	t_node		*tmp;

	tmp = node;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

t_node			*create_node(int x, int y, char *name)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->name = name;
		new_node->visited = 0;
		new_node->distance = 0;
		new_node->coord.x = x;
		new_node->coord.y = y;
		new_node->next = NULL;
		new_node->edges = NULL;
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
