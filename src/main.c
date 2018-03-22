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

static int		check_params(t_lem *params)
{
	if (!params->start)
		return (0);
	if (!params->end)
		return (0);
	if (!params->ants)
		return (0);
	if (!params->rooms)
		return (0);
	if (!params->links)
		return (0);
	return (1);
}

static void		init_params(t_lem *params)
{
	params->start = NULL;
	params->end = NULL;
	params->ants = 0;
	params->rooms = 0;
	params->links = 0;
	params->opl = 0;
	params->graph = NULL;
}

static char		*save_instructions(char *buf, char *new, int i)
{
	char		*instructions;

	instructions = NULL;
	if (i == 1)
		instructions = ft_strjoin_clr(new, "\n", 0);
	else
		instructions = ft_strjoin_clr(buf, ft_strjoin(new, "\n"), 2);
	return (instructions);
}

static int		parser(void)
{
	char		*line;
	t_lem		*params;
	char		*buf;
	int			mod;

	line = NULL;
	buf = NULL;
	mod = 0;
	params = (t_lem *)malloc(sizeof(t_lem));
	init_params(params);
	if (set_ant(params) == 0)
	{
		free(line);
		free_params(params);
		return (2);
	}
	else
		buf = save_instructions(buf, ft_itoa(params->ants), 1);
	while (get_next_line(0, &line) == 1)
	{
		buf = save_instructions(buf, line, 2);
		if (set_start(line, params, &mod) == 1)
			;
		else if (set_end(line, params, &mod) == 1)
			;
		else if (is_comment(line) == 1)
			;
		else if ((set_room(line, params, &mod, &params->graph)))
			;
		else if (set_link(line, params, &params->graph) == 1)
			;
		else
		{
			free(line);
			break ;
		}
		free(line);
	}
	if (check_params(params) == 1)
	{
		if (solver(params, buf) == 0)
		{
			free_params(params);
			free(buf);
			return (4);
		}
		free_params(params);
		free(buf);
		return (1);
	}
	free_params(params);
	free(buf);
	return (3);
}

int				main(void)
{
	int			result;

	result = parser();
	if (result == 1)
		;
	else if (result == 2)
		ft_printf("ERROR\n");
	else if (result == 3)
		ft_printf("ERROR\n");
	else if (result == 4)
		ft_printf("ERROR\n");
	else
		ft_printf("ERROR\n");
	return (0);
}
