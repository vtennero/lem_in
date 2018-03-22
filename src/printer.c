/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:11:51 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:11:53 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_results(char **tab, int len)
{
	int			i;

	i = 0;
	while (i < len + 1)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

static char		**fill_tab(t_link *path, int len)
{
	char		**tab;
	t_link		*tmp;
	t_link		*to_free;
	int			i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (tab)
	{
		tmp = path;
		while (i < len + 1)
		{
			tab[i] = ft_strdup(tmp->connection->name);
			to_free = tmp;
			tmp = tmp->next;
			free(to_free);
			to_free = NULL;
			i++;
		}
	}
	return (tab);
}

static void		print_line(t_ant *ant_list, char **tab)
{
	t_ant		*tmp;

	tmp = ant_list;
	while (tmp)
	{
		ft_printf("L%d-%s", tmp->rank, tab[tmp->pos]);
		if (tmp->next == NULL)
			ft_printf("\n");
		else
			ft_printf(" ");
		tmp = tmp->next;
	}
}

static void		increment_ants(t_ant *ant_list, int rooms_count)
{
	t_ant		*tmp;

	tmp = ant_list;
	while (tmp)
	{
		if (tmp->pos < rooms_count + 1)
			tmp->pos++;
		tmp = tmp->next;
	}
}

void			print_result(t_link *path, int len, t_lem *params)
{
	char		**tab;
	int			nb_turns;
	int			turn_no;
	int			rank;
	t_ant		*ant_list;

	ant_list = NULL;
	rank = 1;
	turn_no = 0;
	nb_turns = params->ants + len;
	tab = fill_tab(path, len);
	if (tab)
	{
		while (turn_no < nb_turns)
		{
			if (rank < params->ants + 1)
				ant_list = pushback_ant(ant_list, create_ant(rank++));
			increment_ants(ant_list, len);
			if (ant_list->pos == len + 1)
				ant_list = search_and_destroy(ant_list);
			print_line(ant_list, tab);
			turn_no++;
		}
		free_results(tab, len);
	}
}
