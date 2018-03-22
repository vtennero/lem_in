/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:33:58 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/15 12:33:59 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			set_ant(t_lem *params)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
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
		return (1);
	}
	free(line);
	return (0);
}
