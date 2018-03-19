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

t_link		*enqueue(t_node *node, t_link *to_visit, int dist)
{
	t_link	*tmp;

	ft_printf("enqueue %s\n", node->name);
	if (to_visit)
		ft_printf("begin of the list = %s\n", to_visit->connection->name);
	tmp = to_visit;
	while (tmp != NULL)
		tmp = tmp->next;
	if (!(tmp = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	node->visited = 1;
	node->distance = dist;
	tmp->connection = node;
	tmp->next = NULL;
	ft_printf("return %s\n", tmp->connection->name);
	return (to_visit);
}

t_link		*dequeue_first(t_link *to_visit)
{
	t_link	*new_start;

	new_start = to_visit->next;
	free(to_visit);
	to_visit = NULL;
	return (new_start);
}

static int	set_distance(t_node *node, t_node *end, int dist)
{
	t_link	*lnk;

	ft_printf("setting %d dist from %s\n", dist, node->name);
	// ft_printf("set dist\n");
	node->visited = 1;
	node->distance = dist;
	lnk = node->edges;
	while (lnk)
	{
		if (ft_strcmp(lnk->connection->name, end->name) == 0)
			break ;
		if (lnk->connection->visited == 0)
			set_distance(lnk->connection, end, dist + 1);
		lnk = lnk->next;
	}
	return (0);
}

t_link			*create_visit(t_node *node, int dist)
{
	t_link		*new_visit;

	new_visit = (t_link *)malloc(sizeof(t_link));
	if (new_visit)
	{
		new_visit->connection = node;
		new_visit->next = NULL;
		node->distance = dist;
		node->visited = 1;
	}
	return (new_visit);
}

t_link			*pushback_to_visit(t_link *start, t_link *new)
{
	t_link		*tmp;

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

void		solver(t_lem *params)
{
	t_node	*start;
	t_node	*end;
	t_link	*tmp;
	t_link	*tmp2;
	t_link	*to_visit;

	to_visit = NULL;
	start = fetch_node(params->graph, params->start);
	start->visited = 1;
	end = fetch_node(params->graph, params->end);
	tmp = start->edges;
	while (tmp)
	{
		if (tmp->connection->visited == 0)
		{
			ft_printf("1. not visited %s\n", tmp->connection->name);
			to_visit = pushback_to_visit(to_visit, create_visit(tmp->connection, 1));
			// to_visit = (tmp->connection, to_visit, 1);
			// ft_printf("to visit set, first element %s\n", to_visit->connection->name);
		}
		tmp = tmp->next;
	}
	// ft_printf("to visit set, first element %s\n", to_visit->connection->name);

	tmp2 = to_visit->connection->edges;
	while (tmp2)
	{
		ft_printf("2. visiting %s\n", tmp2->connection->name);
		// to_visit = dequeue_first(to_visit);
		if (tmp2->connection->visited == 0)
			to_visit = pushback_to_visit(to_visit, create_visit(tmp2->connection, 2));
		tmp2 = tmp2->next;
	}
	tmp2 = to_visit->next->connection->edges;
	while (tmp2)
	{
		ft_printf("2. visiting %s\n", tmp2->connection->name);
		// to_visit = dequeue_first(to_visit);
		if (tmp2->connection->visited == 0)
			to_visit = pushback_to_visit(to_visit, create_visit(tmp2->connection, 2));
		tmp2 = tmp2->next;
	}
	// set_distance(start, end, 0);
	ft_printf("distances set\n");
	print_nodes(params);
}

