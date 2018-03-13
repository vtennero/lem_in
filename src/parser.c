/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:46:50 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/04 18:47:14 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			set_ant(t_lem *params)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	params->ants = 0;
	get_next_line(0, &line);
	if (ft_strlen(line) > 0)
	{
		while (i < (int)ft_strlen(line))
		{
			if (ft_isdigit(line[i]) == 0 || line[0] == '0')
			{
				free(line);
				return (0);
			}
			params->ants = 10 * params->ants + line[i] - '0';
			i++;
		}
		free(line);
		ft_printf("i %d ants %d\n", i, params->ants);
		return (1);
	}
	free(line);
	return (0);
}

int			is_start(char *str)
{
	if (ft_strlen(str) == 7 && ft_strstr(str, "##start"))
		return (1);
	return (0);
}

int			is_end(char *str)
{
	if (ft_strlen(str) == 5 && ft_strstr(str, "##end"))
		return (1);
	return (0);
}

int			parse_coord(char *str, int len)
{
	int		i;
	int		coord;

	i = 0;
	while (i < len)
	{
		if (!(*str) || !(ft_isdigit(*str) == 1))
			return(-1);
		coord = str[i++] + '0' + 10 *coord;
	}
	// ft_printf("coord read = %d\n", coord);
	return (coord);
}

int			is_room(char *str)
{
	int		i;
	int		x_space;
	int		y_space;
	int		x;
	int		y;

	i = 0;
	x_space = ft_char_pos(str, ' ');
	y_space = ft_char_pos(str + x_space + 1, ' ');
	// ft_printf("x_space = %d\n", x_space);
	// ft_printf("y_space = %d\n", y_space);
	if (x_space == -1 || y_space == -1)
		return (0);
	x = parse_coord(str + x_space, y_space - (x_space + 1));
	y = parse_coord(str + y_space, ft_char_pos(str, '\0') - (y_space + 1));
	if (x == -1 || y == -1)
		return (0);
	// ft_printf("x = %d y = %d\n", x, y);
	return (1);
}

int			is_start_room(t_lem *params)
{
	char	*line;

	line = NULL;
	if (!(get_next_line(0, &line) == 1))
		return (0);
	if (is_room(line))
	{
		params->start = ft_strndup(line, ft_char_pos(line, ' '));
		return (1);
	}
	return (0);
}

int			is_end_room(t_lem *params)
{
	char	*line;

	line = NULL;
	if (!(get_next_line(0, &line) == 1))
		return (0);
	// ft_printf("////////////////////////%s\n", line);
	if (is_room(line))
	{
		params->end = ft_strndup(line, ft_char_pos(line, ' '));
		return (1);
	}
	return (0);
}

int			set_start(char *line, t_lem *params)
{
	if (params->start == NULL && is_start(line) == 1 && is_start_room(params) == 1)
	{
		// params->start = ft_strdup("on a la start room");
		// ft_printf("%s\n", params->start);
		return (1);
	}
	return (0);
}

int			is_comment(char *line)
{
	if (ft_strlen(line) >= 1 && line[0] == '#')
		return (1);
	return (0);
}

int			set_room(char *line)
{
	if (is_room(line))
		return (1);
	return (0);
}

int			set_end(char *line, t_lem *params)
{
	// ft_printf("is end returns%d\n", is_end(line));
	// ft_printf("is end room returns%d\n", is_end_room(params));
	if (params->end == NULL && is_end(line) == 1 && is_end_room(params) == 1)
	{
		// params->start = ft_strdup("on a la start room");
		// ft_printf("%s\n", params->end);
		return (1);
	}
	return (0);
}

int			set_link(char *line)
{
	int		dash;

	dash = ft_char_pos(line, '-');
	if (dash == -1)
		return (0);
	if (ft_strncmp(line, line + dash + 1, dash))
		return (1);
	return (0);
}