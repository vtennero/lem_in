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

static int	set_distance(t_node *node, int dist)
{
	t_link	*lnk;

	node->visited = 1;
	node->distance = dist;
	lnk = node->edges;
	while (lnk)
	{
		if (lnk->connection->visited == 0)
			set_distance(lnk->connection, dist + 1);
		lnk = lnk->next;
	}
	return (1);
}

void	solver(t_lem *params)
{
	t_node	*start;

	start = fetch_node(params->graph, params->start);
	set_distance(start, 0);
	ft_printf("distances set\n");
	print_nodes(params);
}

