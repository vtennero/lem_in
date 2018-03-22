/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:04 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 16:41:00 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_valid_link(char *str, t_node *node, char *a, char *b)
{
	int			counter_a;
	int			counter_b;
	t_node		*tmp;
	int			dash;

	dash = ft_char_pos(str, '-');
	counter_a = 0;
	counter_b = 0;
	tmp = node;
	if (ft_strcmp(a, b) == 0)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, a) == 0)
			counter_a++;
		if (ft_strcmp(tmp->name, b) == 0)
			counter_b++;
		tmp = tmp->next;
	}
	if (counter_a != 1 || counter_b != 1)
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

static int		fetch_and_assign(t_lem *params, t_node **node, char *a, char *b)
{
	t_node		*node_a;
	t_node		*node_b;

	params->links += 1;
	node_a = fetch_node(*node, a);
	node_b = fetch_node(*node, b);
	assign_edge(node_a, node_b);
	assign_edge(node_b, node_a);
	free(a);
	free(b);
	return (1);
}

int				set_link(char *line, t_lem *params, t_node **node)
{
	int			dash;
	char		*room_one;
	char		*room_two;

	dash = ft_char_pos(line, '-');
	if (dash == -1 || \
			!params->end || !params->start || !params->rooms)
		return (0);
	if (!(room_one = ft_strndup(line, dash)))
		return (0);
	if (!(room_two = ft_strdup(line + dash + 1)))
	{
		free(room_one);
		return (0);
	}
	if ((is_valid_link(line, *node, room_one, room_two) == 0))
	{
		free(room_one);
		free(room_two);
		return (0);
	}
	return (fetch_and_assign(params, node, room_one, room_two));
}
