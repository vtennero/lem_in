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

void	solver(t_lem *params)
{
	t_node	*start;
	t_node	*end;

	start = fetch_node(params->graph, params->start);
	end = fetch_node(params->graph, params->end);
	set_distance(start, end, 0);
	ft_printf("distances set\n");
	print_nodes(params);
}

