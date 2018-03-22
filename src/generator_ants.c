/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:10:56 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:44:21 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*create_ant(int rank)
{
	t_ant		*new_ant;

	new_ant = (t_ant *)malloc(sizeof(t_ant));
	if (new_ant)
	{
		new_ant->pos = 0;
		new_ant->rank = rank;
		new_ant->next = NULL;
	}
	return (new_ant);
}

t_ant			*pushback_ant(t_ant *start, t_ant *new)
{
	t_ant		*tmp;

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

t_ant			*search_and_destroy(t_ant *ant_list)
{
	t_ant		*new_start;

	new_start = ant_list->next;
	free(ant_list);
	ant_list = NULL;
	return (new_start);
}
