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

int			set_ant(char *line, t_lem *params)
{
	if (line)
	{
		if (ft_atoi(line) > 0)
		{
			params->ants = ft_atoi(line);
			return (1);
		}
	}
	return (0);
}

int			is_start(char *str)
{
	if (ft_strlen(str) == 7 && ft_strstr(str, "##start"))
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
	ft_printf("coord read = %d\n", coord);
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
	x_space = ft_strchr(str, ' ');
	y_space = ft_strchr(str + x_space + 1, ' ');
	if (x_space == 0 || y_space == 0)
		return (0);
	x = parse_coord(str, y_space - (x_space + 1));
	y = parse_coord(str, ft_strchr(str, '\0'));
	if (x == -1 || y == -1)
		return (0);
	ft_printf("x = %d y = %d\n", x, y);
	return (1);
}

int			is_start_room(t_lem *params)
{
	char	*line;

	if (!(get_next_line(0, &line) == 1))
		return (0);
	if (is_room(line))
		return (1);
	return (0);
}

int			set_start(char *line, t_lem *params)
{
	line = NULL;
	if (params->start == NULL)
	{
		if (is_start(line) == 1 && is_start_room(params) == 1)
		params->start = ft_strdup("on a la start room");
		ft_printf("%s\n", params->start);
		return (1);
	}
	return (0);
}

int			is_comment(char *line)
{
	line = NULL;
	return (0);
}

int			set_room(char *line)
{
	line = NULL;
	return (0);
}

int			set_end(char *line)
{
	line = NULL;
	return (0);
}

int			set_link(char *line)
{
	line = NULL;
	return (0);
}