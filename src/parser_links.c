/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:04 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/15 12:32:07 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_edges(t_node *node)
{
	t_link	*tmp;

	ft_printf("free edges for %s\n", node->name);
	if (!node->edges)
		ft_printf("node->edges doesnt exist\n");
	while (node->edges)
	{
		tmp = node->edges;
		ft_printf("freeing edge %s for %s\n", node->edges->connection->name, node->name);
		node->edges = node->edges->next;
		free(tmp);
		tmp = NULL;
	}
}

static int	is_valid_link(char *str, int dash, t_node *node)
{
	char	*room_one;
	char	*room_two;
	int		counter;

	counter = 0;
	room_one = ft_strndup(str, dash);
	room_two = ft_strdup(str + dash + 1);
	// ft_printf("room one %s room two %s\n", room_one, room_two);
	if (room_one && room_two)
	{
		if (ft_strcmp(room_one, room_two) == 0)
			{
				free(room_one);
				free(room_two);
				// ft_printf("rooms are identical\n");
				return (0);
			}
		while (node)
		{
			// ft_printf("loop\n");
			if (ft_strcmp(node->name, room_one) == 0 || ft_strcmp(node->name, room_two) == 0)
				counter++;
			// ft_printf("node->name = |%s| versus room_one = |%s| and room_two = |%s|\n", node->name, room_one, room_two);
			node = node->next;
		}
	}
	// ft_printf("free(room_one)\n");
	free(room_one);
	// ft_printf("free(room_two)\n");
	free(room_two);
	if (counter != 2)
		return (0);
	return (1);
}

t_link			*create_edge(t_node *node)
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

// t_link			*pushback_edge(t_link *start, t_node *new)
// {
// 	t_link		*tmp;

// 	tmp = NULL;
// 	if (!start)
// 		return (new);
// 	// ft_printf("start->name = |%s|\n", start->name);
// 	if (new)
// 	{
// 		tmp = start;
// 		while (tmp->next != NULL)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// 	// ft_printf("after :start->name = |%s|\n", start->name);
// 	return (start);
// }

int			assign_edge(t_node *node_a, t_node *node_b)
{
	t_link	*tmp;
	// t_link	*last;
	
	// ft_printf("assign_edge for %s-%s\n", node_a->name, node_b->name);
	if (!node_a->edges)
	{
		// ft_printf("creating first edge\n");
		node_a->edges = create_edge(node_b);
		return (1);
	}
	tmp = node_a->edges;
	while (tmp->next != NULL)
	{
		// ft_printf("loop\n");
		// ft_printf("connection = %s\n", node_a->edges->connection->name);
		if (ft_strcmp(tmp->connection->name, node_b->name) == 0)
			return (0);
		// node_a->edges = node_a->edges->next;
		// last = tmp;
		tmp = tmp->next;
	}
	// ft_printf("endof loop\n");
	// ft_printf("connection to be added = %s\n", node_b->name);
	tmp->next = create_edge(node_b);
	// last->next = tmp;
	// ft_printf("new edge is %s\n", node_a->edges->connection->name);
	return (1);
	// ft_printf("assign_edge for %s-%s\n", node_a->name, node_b->name);
	// if (node_a->edges !=NULL)
	// {
	// 	while (node_a->edges != NULL)
	// 	{
	// 		ft_printf("loop /connection = %s\n", node_a->edges->connection->name);
	// 		tmp = node_a->edges;
	// 		node_a->edges = node_a->edges->next;
	// 	}
	// 	ft_printf("endof loop\n");
	// 	tmp->next = node_a->edges;
	// }
	// ft_printf("connection to be added to %s = %s\n", node_a->name, node_b->name);
	// node_a->edges = (t_link *)malloc(sizeof(t_link));
	// node_a->edges->next = NULL;
	// node_a->edges->connection = node_b;
	// ft_printf("new edge is %s\n", node_a->edges->connection->name);
}

int			set_link(char *line, t_lem *params, t_node *node)
{
	int		dash;
	t_node	*node_a;
	t_node	*node_b;
	char	*room_one;
	char	*room_two;

	room_one = NULL;
	room_two = NULL;
	// ft_printf("////////////////////////%s\n", line);
	dash = ft_char_pos(line, '-');
	// ft_printf("dash = %d\n", dash);
	// if (!(dash == -1) && (is_valid_link(line, dash)))
	if (dash == -1 || (is_valid_link(line, dash, node) == 0) \
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
	node_a = fetch_node(node, room_one);
	node_b = fetch_node(node, room_two);
	assign_edge(node_a, node_b);
	assign_edge(node_b, node_a);
	// node_a->edges = pushback_edge(node_a->edges, node_b);
	// node_b->edges = pushback_edge(node_b->edges, node_a);
	free (room_one);
	free (room_two);
	return (1);
}

// int			check_link_format(char *str, int dash)
// {
// 	int		i;
// 	int		len;

// 	ft_printf("checking link format\n");
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		if (i != dash && ft_isdigit(str[i]) == 0)
// 			{
// 				ft_printf("i = ; dash = ; ")
// 			return (0);
// 			}
// 		i++;
// 	}
// 	ft_printf("correct format\n");
// 	return (1);
// }