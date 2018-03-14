/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:08:18 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/14 11:59:54 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_node
{
	char			*name;
	int				visited;
	struct s_links	*edges;
	struct s_node	*next;
	struct s_point	coord;
}					t_node;

typedef struct		s_links
{
	struct s_node	*connection;
	struct s_links	*next;
}					t_links;

typedef struct		s_lem
{
	int				ants;
	char			*start;
	char			*end;
	int				rooms;
	int				links;
	struct s_node	*graph;
}					t_lem;



/*
 ** ------------------------- PARSER -------------------------
 */
int			set_ant(t_lem *params);
int			set_start(char *line, t_lem *params);
int			is_comment(char *line);
t_node		*set_room(char *line);
int			set_end(char *line, t_lem *params);
int			set_link(char *line);
t_node		*create_node(int x, int y, char *name);
t_node		*pushback_node(t_node *start, t_node *new);
// t_node		*build_graph(t_lem *params);

/*
 ** ------------------------- SOLVER -------------------------
 */

/*
 ** ------------------------- UTILITIES -------------------------
 */

#endif
