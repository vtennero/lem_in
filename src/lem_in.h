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
	struct s_link	*edges;
	struct s_node	*next;
	struct s_point	coord;
}					t_node;

typedef struct		s_link
{
	struct s_node	*connection;
	struct s_link	*next;
}					t_link;

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
int					set_ant(t_lem *params);
int					set_start(char *line, t_lem *params, int *mod);
int					is_comment(char *line);
int					set_room(char *line, t_lem *params, int *mod, t_node **graph);
int					set_end(char *line, t_lem *params, int *mod);
int					set_link(char *line, t_lem *params, t_node *node);
/*
 ** ------------------------- SOLVER -------------------------
 */

/*
 ** ------------------------- UTILITIES -------------------------
 */
t_node				*create_node(int x, int y, char *name);
t_node				*pushback_node(t_node *start, t_node *new);
// t_node			*build_graph(t_lem *params);
void				free_edges(t_node *node);
t_node				*free_node(t_node *node);
void				print_nodes(t_node *node);
t_node				*fetch_node(t_node *node, char *name);


#endif
