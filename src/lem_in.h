/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:08:18 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/04 18:08:27 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_lem
{
	int				ants;
	char*			start;
	char*			end;
	int				rooms;
	int				links;
}					t_lem;

/*
** ------------------------- PARSER -------------------------
*/
int			set_ant(t_lem *params);
int			set_start(char *line, t_lem *params);
int			is_comment(char *line);
int			set_room(char *line);
int			set_end(char *line, t_lem *params);
int			set_link(char *line);
/*
** ------------------------- SOLVER -------------------------
*/

/*
** ------------------------- UTILITIES -------------------------
*/

#endif