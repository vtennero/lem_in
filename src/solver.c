/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:39:04 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:51:05 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*get_path(t_lem *params)
{
	t_node		*start;
	t_node		*end;
	t_link		*path;
	t_link		*tmp;
	int			dist;

	start = fetch_node(params->graph, params->start);
	end = fetch_node(params->graph, params->end);
	params->opl = end->distance;
	path = NULL;
	path = enqueue(path, end, -1);
	dist = params->opl;
	while (dist != -1)
	{
		tmp = path->connection->edges;
		while (tmp)
		{
			if (tmp->connection->distance == dist - 1 && tmp->connection->visited == 1)
			{
				path = enqueue(path, tmp->connection, -1);
				break ;
			}
			tmp = tmp->next;
		}
		dist--;
	}
	return (path);
}

static int		traverse_graph(t_lem *params)
{
	t_node		*start;
	t_node		*end;
	t_link		*queue;
	t_node		*visiting;
	t_link		*tmp;

	queue = NULL;
	start = fetch_node(params->graph, params->start);
	end = fetch_node(params->graph, params->end);
	queue = enqueue(queue, start, 0);
	while (queue)
	{
		visiting = queue->connection;
		tmp = visiting->edges;
		queue = dequeue(queue);
		while (tmp)
		{
			if (tmp->connection->visited == 0)
				queue = enqueue(queue, tmp->connection, visiting->distance + 1);
			if (ft_strcmp(tmp->connection->name, end->name) == 0)
				return (free_queue(queue));
			tmp = tmp->next;
		}
	}
	return (0);
}

int				solver(t_lem *params, char *buf)
{
	t_link		*optimal_path;

	if (!(traverse_graph(params) == 1))
		return (0);
	if ((optimal_path = get_path(params)))
	{
		ft_printf("%s\n", buf);
		print_result(optimal_path, fetch_node(params->graph, params->end)->distance, params);
	}
	return (1);
}
