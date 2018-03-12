/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:05:41 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/04 18:05:45 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	char		*line;
	t_lem		params;

	line = NULL;
	params.start = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (set_ant(line, &params) == 1)
			ft_printf("ant set\n");
		else if (set_start(line, &params) == 1)
			ft_printf("start set\n");
		else if (is_comment(line) == 1)
			ft_printf("comment\n");
		else if (set_room(line) == 1)
			ft_printf("room set\n");
		else if (set_end(line) == 1)
			ft_printf("end set\n");
		else if (set_link(line) == 1)
			ft_printf("link set\n");
		else
		{
			ft_printf("ERROR\n");
			break ;
		}
	}
	ft_printf("ERROR\n");
	return (0);
}