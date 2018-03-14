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

int		check_params(t_lem *params)
{
	ft_printf("start : %s\n", params->start);
	ft_printf("end : %s\n", params->end);
	ft_printf("ants : %d\n", params->ants);
	if (!params->start)
		return (0);
	if (!params->end)
		return (0);
	if (!params->ants)
		return (0);
	// if (!params->rooms)
	// if (!params->start)
	return (1);
}

void	init_params(t_lem *params)
{
	params->start = NULL;
	params->end = NULL;
	params->ants = 0;
	params->rooms = 0;
	params->links = 0;
	params->graph = NULL;
}

void	free_params(t_lem *params)
{
	// ft_memdel(params);
	free(params);
	params = NULL;
}

int		main(void)
{
	char		*line;
	t_lem		*params;
	t_node		*graph;

	line = NULL;
	graph = NULL;
	params = (t_lem *)malloc(sizeof(t_lem));
	init_params(params);
	if (set_ant(params) == 0)
	{
		ft_printf("ERROR\n");
		free(line);
		free_params(params);
		return (0);
	}
	else
	{
		free(line);
		ft_printf("ant set\n");
	}
	while (get_next_line(0, &line) == 1)
	{
		if (set_start(line, params) == 1)
			ft_printf("start set\n");
		else if (set_end(line, params) == 1)
			ft_printf("end set\n");
		else if (is_comment(line) == 1)
			ft_printf("comment\n");
		else if ((graph = set_room(line)))
			ft_printf("room set\n");
		else if (set_link(line) == 1)
			ft_printf("link set\n");
		else
			{
				ft_printf("FUNCTION ERROR on %s\n", line);
				free_params(params);
				return(0);
			}
		free(line);
	}
	if (check_params(params) == 1)
		ft_printf("ALL CLEAR\n");
	else
		ft_printf("PARAMS ERROR\n");
	free_params(params);
	return (0);
}