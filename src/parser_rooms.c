/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:34:26 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/15 12:34:27 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	parse_coord(char *str, int len)
{
	int		i;
	int		coord;

	i = 0;
	coord = 0;
	if (len < 1)
		return (-1);
	while (i < len)
	{
		if (!(ft_isdigit(str[i]) == 1))
			return (-1);
		coord = 10 * coord + str[i++] - '0';
	}
	return (coord);
}

static int	is_room(char *str, int *x, int *y)
{
	int		i;
	int		x_space;
	int		y_space;

	i = 0;
	x_space = ft_char_pos(str, ' ');
	y_space = ft_char_pos(str + x_space + 1, ' ') + x_space + 1;
	if (x_space == -1 || y_space == -1)
		return (0);
	*x = parse_coord(str + x_space + 1, y_space - (x_space + 1));
	*y = parse_coord(str + y_space + 1, ft_strlen(str + y_space + 1));
	if (*x == -1 || *y == -1)
		return (0);
	return (1);
}

static int		is_duplicate_room(t_node *new, t_node *start)
{
	t_node		*tmp;

	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, new->name) == 0)
		{
			free_node(new);
			return (1);
		}
		if (tmp->coord.x == new->coord.x && tmp->coord.y == new->coord.y)
		{
			free_node(new);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			set_room(char *line, t_lem *params, int *mod, t_node **graph)
{
	t_node		*new;
	int			x;
	int			y;
	char		*name;

	new = NULL;
	if (is_room(line, &x, &y))
	{
		name = ft_strndup(line, ft_char_pos(line, ' '));
		new = create_node(x, y, name);
		if (!name || is_duplicate_room(new, *graph))
			return (0);
		*graph = pushback_node(*graph, new);
		if (*mod == 1 && params->start == NULL)
		{
			*mod = 3;
			params->start = ft_strdup(new->name);
		}
		if (*mod == 2 && params->end == NULL)
		{
			*mod = 3;
			params->end = ft_strdup(new->name);
		}
		params->rooms += 1;
		return (1);
	}
	*mod = 3;
	return (0);
}
