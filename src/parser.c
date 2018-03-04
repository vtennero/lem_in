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

int			set_ant(char *line)
{
	if (line)
	{
		if (ft_atoi(line) > 0)
			return (1);
	}
	return (0);
}

int			set_start(char *line)
{
	line = NULL;
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