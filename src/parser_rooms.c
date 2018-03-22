/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:34:26 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 16:07:42 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		parse_coord(char *str, int len)
{
	int			i;
	int			coord;

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

static int		is_room(char *str, int *x, int *y)
{
	int			i;
	int			x_space;
	int			y_space;

	i = 0;
	x_space = ft_char_pos(str, ' ');
	y_space = ft_char_pos(str + x_space + 1, ' ') + x_space + 1;
	if (x_space == -1 || y_space == -1 || ft_strlen(str) == 0 || str[0] == 'L')
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

static int		update_params(t_lem *params, int mod, t_node *new)
{
	int			result;

	result = mod;
	if (mod == 1 && params->start == NULL)
	{
		result = 3;
		params->start = ft_strdup(new->name);
	}
	if (mod == 2 && params->end == NULL)
	{
		result = 3;
		params->end = ft_strdup(new->name);
	}
	params->rooms += 1;
	return (result);
}

int				set_room(char *line, t_lem *params, int *mod, t_node **gr)
{
	t_node		*new;
	int			x;
	int			y;
	char		*name;

	if (is_room(line, &x, &y) && params->links == 0)
	{
		name = ft_strndup(line, ft_char_pos(line, ' '));
		if (!name)
			return (0);
		new = create_node(x, y, name);
		if (is_duplicate_room(new, *gr))
			return (0);
		*gr = pushback_node(*gr, new);
		*mod = update_params(params, *mod, new);
		return (1);
	}
	*mod = 3;
	return (0);
}
