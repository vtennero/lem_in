/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:27:48 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/18 15:27:50 by vtennero         ###   ########.fr       */
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
		// ft_printf("loop %s\n", node->name);
		lnk = node->edges;
		// ft_printf("Node %s : freeing edge %s\n", node->name, node->edges->connection->name);
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

	// ft_printf("free nodes\n");
	free_edges(params);
	while(params->graph)
	{
		// ft_printf("launching frees for %s\n", params->graph->name);
		// ft_printf("%s s first edge is %s\n", params->graph->name, params->graph->edges->connection->name);
		tmp = params->graph;
		// free_edges(params);
		free(params->graph->name);
		params->graph->name = NULL;
		params->graph = params->graph->next;
		free(tmp);
		tmp = NULL;
	}
	// ft_printf("free nodes done\n");
	return (0);
}

t_node			*free_node(t_node *node)
{
	free(node->name);
	node->name = NULL;
	free(node);
	node = NULL;
	return (0);
}

void			free_params(t_lem *params)
{
	// ft_memdel(&params);

	// ft_printf("free params\n");
	free(params->start);
	params->start = NULL;
	free(params->end);
	params->end = NULL;
	// ft_printf("free params->graph\n");
	free_nodes(params);
	// ft_printf("free params->graph done\n");
	free(params);
	params = NULL;
}