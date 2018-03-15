/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:34:06 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/15 12:34:08 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_comment(char *line)
{
	if (ft_strlen(line) >= 1 && line[0] == '#')
		return (1);
	return (0);
}

int			is_start(char *str)
{
	if (ft_strlen(str) == 7 && ft_strcmp(str, "##start") == 0)
		return (1);
	return (0);
}

int			is_end(char *str)
{
	if (ft_strlen(str) == 5 && ft_strcmp(str, "##end") == 0)
		return (1);
	return (0);
}

int			set_start(char *line, t_lem *params, int *mod)
{
	if (params->start == NULL && is_start(line) == 1)
	{
		*mod = 1;
		// params->start = ft_strdup("on a la start room");
		// ft_printf("%s\n", params->start);
		return (1);
	}
	return (0);
}

int			set_end(char *line, t_lem *params, int *mod)
{
	// ft_printf("is end returns%d\n", is_end(line));
	// ft_printf("is end room returns%d\n", is_end_room(params));
	if (params->end == NULL && is_end(line) == 1)
	{
		*mod = 2;
		// params->start = ft_strdup("on a la start room");
		// ft_printf("%s\n", params->end);
		return (1);
	}
	return (0);
}

// int			is_start_room(t_lem *params)
// {
// 	char	*line;
// 	int		x;
// 	int		y;

// 	line = NULL;
// 	if (!(get_next_line(0, &line) == 1))
// 		return (0);
// 	if (is_comment(line))
// 	{
// 		free(line);
// 		return (is_start_room(params));
// 	}
// 	if (is_room(line, &x, &y))
// 	{
// 		params->start = ft_strndup(line, ft_char_pos(line, ' '));
// 		return (1);
// 	}
// 	return (0);
// }

// int			is_end_room(t_lem *params)
// {
// 	char	*line;
// 	int		x;
// 	int		y;

// 	line = NULL;
// 	if (!(get_next_line(0, &line) == 1))
// 		return (0);
// 	// ft_printf("////////////////////////%s\n", line);
// 	if (is_comment(line))
// 	{
// 		free(line);
// 		return (is_end_room(params));
// 	}
// 	if (is_room(line, &x, &y))
// 	{
// 		params->end = ft_strndup(line, ft_char_pos(line, ' '));
// 		return (1);
// 	}
// 	return (0);
// }