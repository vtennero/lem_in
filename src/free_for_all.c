/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:27:48 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:44:14 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_edges(t_lem *params)
{
	t_link	*lnk;
	t_node	*node;

	node = params->graph;
	while (node)
	{
		while (node->edges)
		{
			lnk = node->edges;
			node->edges = node->edges->next;
			free(lnk);
			lnk = NULL;
		}
		node = node->next;
	}
}

static int		*free_nodes(t_lem *params)
{
	t_node		*tmp;

	free_edges(params);
	while (params->graph)
	{
		tmp = params->graph;
		free(params->graph->name);
		params->graph->name = NULL;
		params->graph = params->graph->next;
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

void			free_params(t_lem *params)
{
	free(params->start);
	params->start = NULL;
	free(params->end);
	params->end = NULL;
	free_nodes(params);
	free(params);
	params = NULL;
}
