/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:05:41 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/22 17:26:23 by vtennero         ###   ########.fr       */
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

static int		parser(t_lem *params)
{
	char		*l;
	char		*buf;
	int			mod;
	int			result;

	l = NULL;
	buf = NULL;
	mod = 0;
	if (set_ant(params) == 0)
		return (2);
	else
		buf = save_instructions(buf, ft_itoa(params->ants), 1);
	while (get_next_line(0, &l) == 1)
	{
		buf = save_instructions(buf, l, 2);
		if (!(set_start(l, params, &mod)) && !(set_end(l, params, &mod))
				&& !(is_com(l)) && !(set_room(l, params, &mod, &params->graph))
				&& !(set_link(l, params, &params->graph)))
			break ;
		free(l);
	}
	free(l);
	result = (check_params(params) && solver(params, buf)) ? 1 : 0;
	free(buf);
	return (result);
}

int				main(void)
{
	int			result;
	t_lem		*params;

	if (!(params = (t_lem *)malloc(sizeof(t_lem))))
		return (0);
	init_params(params);
	result = parser(params);
	if (result != 1)
		ft_printf("ERROR\n");
	free_params(params);
	return (0);
}
