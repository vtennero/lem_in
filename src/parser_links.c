/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:04 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 15:46:19 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_valid_link(char *str, int dash, t_node *node)
{
	char		*room_one;
	char		*room_two;
	int			counter;
	t_node		*tmp;

	counter = 0;
	room_one = ft_strndup(str, dash);
	room_two = ft_strdup(str + dash + 1);
	tmp = node;
	if (room_one && room_two)
	{
		if (ft_strcmp(room_one, room_two) == 0)
		{
			free(room_one);
			free(room_two);
			return (0);
		}
		while (tmp)
		{
			if (ft_strcmp(tmp->name, room_one) == 0 || ft_strcmp(tmp->name, room_two) == 0)
				counter++;
			tmp = tmp->next;
		}
	}
	free(room_one);
	free(room_two);
	if (counter != 2)
		return (0);
	return (1);
}

static t_link	*create_edge(t_node *node)
{
	t_link		*new_edge;

	new_edge = (t_link *)malloc(sizeof(t_link));
	if (new_edge)
	{
		new_edge->connection = node;
		new_edge->next = NULL;
	}
	return (new_edge);
}

static int		assign_edge(t_node *node_a, t_node *node_b)
{
	t_link		*tmp;

	if (!node_a->edges)
	{
		node_a->edges = create_edge(node_b);
		return (1);
	}
	tmp = node_a->edges;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->connection->name, node_b->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	tmp->next = create_edge(node_b);
	return (1);
}

int				set_link(char *line, t_lem *params, t_node **node)
{
	int			dash;
	t_node		*node_a;
	t_node		*node_b;
	char		*room_one;
	char		*room_two;

	room_one = NULL;
	room_two = NULL;
	dash = ft_char_pos(line, '-');
	if (dash == -1 || (is_valid_link(line, dash, *node) == 0) \
			|| !params->end || !params->start || !params->rooms)
		return (0);
	params->links += 1;
	if (!(room_one = ft_strndup(line, dash)))
		return (0);
	if (!(room_two = ft_strdup(line + dash + 1)))
	{
		free(room_one);
		return (0);
	}
	node_a = fetch_node(*node, room_one);
	node_b = fetch_node(*node, room_two);
	assign_edge(node_a, node_b);
	assign_edge(node_b, node_a);
	free(room_one);
	free(room_two);
	return (1);
}
