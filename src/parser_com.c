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

int			is_com(char *line)
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
		return (1);
	}
	return (0);
}

int			set_end(char *line, t_lem *params, int *mod)
{
	if (params->end == NULL && is_end(line) == 1)
	{
		*mod = 2;
		return (1);
	}
	return (0);
}
