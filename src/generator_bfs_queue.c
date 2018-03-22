/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_bfs_queue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:08:52 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:44:40 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				free_queue(t_link *queue)
{
	t_link		*tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
	return (1);
}

static t_link	*create_queue_elt(t_node *node, int dist)
{
	t_link		*new_visit;

	new_visit = (t_link *)malloc(sizeof(t_link));
	if (new_visit)
	{
		new_visit->connection = node;
		new_visit->next = NULL;
		if (!(dist == -1))
			node->distance = dist;
		node->visited = 1;
	}
	return (new_visit);
}

t_link			*enqueue(t_link *start, t_node *add, int dist)
{
	t_link		*tmp;
	t_link		*new;

	new = create_queue_elt(add, dist);
	tmp = NULL;
	if (!start)
		return (new);
	if (new)
	{
		if (dist == -1)
		{
			new->next = start;
			start = new;
		}
		else
		{
			tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	return (start);
}

t_link			*dequeue(t_link *element)
{
	t_link		*new_start;

	new_start = element->next;
	free(element);
	element = NULL;
	return (new_start);
}
