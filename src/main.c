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

void	init_params(t_lem *params)
{
	params->start = NULL;
	params->end = NULL;
	params->ants = 0;
	params->rooms = 0;
	params->links = 0;
	params->graph = NULL;
}

char*		save_instructions(char *buf, char *new, int i)
{
	char	*instructions;

	// ft_printf("new line to save: %s\n", new);
	instructions = NULL;
	if (i == 1)
		instructions = ft_strjoin_clr(new, "\n", 0);
	else
		instructions = ft_strjoin_clr(buf, ft_strjoin(new, "\n"), 2);
	return (instructions);
}

int		parser(void)
{
	char		*line;
	t_lem		*params;
	// t_node		*graph;
	char		*buf;
	int			mod;

	line = NULL;
	// graph = NULL;
	buf = NULL;
	mod = 0;
	params = (t_lem *)malloc(sizeof(t_lem));
	init_params(params);
	if (set_ant(params) == 0)
	{
		// ft_printf("ERROR\n");
		free(line);
		free_params(params);
		return (2);
	}
	else
	{
		buf = save_instructions(buf, ft_itoa(params->ants), 1);
		// buf = ft_strjoin_clr(buf, line, 2);
		// ft_printf("ant set\n");
	}
	while (get_next_line(0, &line) == 1)
	{
		buf = save_instructions(buf, line, 2);
		// buf = ft_strjoin_clr(buf, line, 0);
		if (set_start(line, params, &mod) == 1)
		// {
			;
			// ft_printf("nextline is start\n");
			// ft_printf("%s\n", line);
		// }
		else if (set_end(line, params, &mod) == 1)
		// {
			;
			// ft_printf("nextline is end\n");
			// ft_printf("%s\n", line);
		// }
		else if (is_comment(line) == 1)
			// ft_printf("comment\n");
			;
		else if ((set_room(line, params, &mod, &params->graph)))
			// ft_printf("room set\n");
			;
		else if (set_link(line, params, &params->graph) == 1)
			// ft_printf("link set\n");
			;
		else
			{
				// ft_printf("FUNCTION ERROR on %s\n", line);
				// print_nodes(params);
				// params->graph = graph;
				free_params(params);
				free(buf);
				free(line);
				return(0);
			}
		free(line);
	}
	if (check_params(params) == 1)
	{
		solver(params);
		free_params(params);
		free(buf);
		return (1);
	}
	free_params(params);
	free(buf);
	return (3);
	// print_nodes(graph);
	// params->graph = graph;
	// print_nodes(params);
}

int		main(void)
{
	int	result;

	result = parser();
	if (result == 1)
		ft_printf("ALL CLEAR\n");
	else if (result == 2)
		ft_printf("ANTS ERROR\n");
	else if (result == 3)
		ft_printf("PARAMS ERROR");
	else
		ft_printf("ERROR");
	return (0);
}