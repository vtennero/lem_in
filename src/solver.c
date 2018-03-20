/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:39:04 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/18 16:39:06 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static t_link	*enqueue(t_link *start, t_node *add, int dist)
{
	t_link		*tmp;
	t_link		*new;

	// ft_printf("enqueue %s\n", add->name);
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
	// ft_printf("enqueue returns %s\n", start->connection->name);
	return (start);
}

static t_link	*dequeue(t_link *element)
{
	t_link		*new_start;

	new_start = element->next;
	free(element);
	element = NULL;
	return (new_start);
}

t_link			*get_path(t_lem *params)
{
	t_node		*start;
	t_node		*end;
	t_link		*path;
	t_link		*tmp;
	int			dist;

	// ft_printf("--------get path-------\n");
	start = fetch_node(params->graph, params->start);
	end = fetch_node(params->graph, params->end);
	params->opl = end->distance;
	path = NULL;
	path = enqueue(path, end, -1);
	dist = params->opl;
	while (dist != -1)
	{
		// ft_printf("dist that is being searched = %d\n", dist - 1);
		// ft_printf("path top = %s\n", path->connection->name);
		tmp = path->connection->edges;
		while (tmp)
		{
			if (tmp->connection->distance == dist - 1 && tmp->connection->visited == 1)
			{
				// ft_printf("adding %s\n", tmp->connection->name);
				path = enqueue(path, tmp->connection, -1);
				break ;
				// if (ft_strcmp(tmp->connection->name, start->name) == 0)
					// break ; 
			}
			tmp = tmp->next;
		}
		dist--;
	}
	return (path);
}

int			free_queue(t_link *queue)
{
	t_link	*tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free (tmp);
	}
	return (1);
}

int			traverse_graph(t_lem *params)
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

void			print_optimal_path(t_link *path, int len)
{
	t_link		*tmp;
	t_link		*to_free;
	int			i;

	i = 0;
	tmp = path;
	while (i < len + 1)
	{
		if (i != len)
			ft_printf("%s -> ", tmp->connection->name);
		else
			ft_printf("%s\n", tmp->connection->name);
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
		to_free = NULL;
		i++;
	}
}

int				solver(t_lem *params)
{
	t_link		*optimal_path;

	if (!(traverse_graph(params) == 1))
		return (0);
	if ((optimal_path = get_path(params)))
		print_optimal_path(optimal_path, fetch_node(params->graph, params->end)->distance);
	// print_nodes(params);
	return (1);
}
