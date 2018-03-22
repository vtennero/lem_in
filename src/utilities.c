/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:05:38 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:05:49 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_nodes(t_lem *params)
{
	t_node	*tmp;
	t_link	*lnk;

	tmp = params->graph;
	ft_printf("PRINT NODES & EDGES\n");
	ft_printf("start : %s\n", params->start);
	ft_printf("end : %s\n", params->end);
	ft_printf("ants : %d\n", params->ants);
	while (tmp)
	{
		lnk = tmp->edges;
		ft_printf("Node %s with distance = %d", tmp->name, tmp->distance);
		ft_printf(", visited = %d, connected to: ", tmp->visited);
		while (lnk != NULL)
		{
			ft_printf("%s ", lnk->connection->name);
			lnk = lnk->next;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
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
