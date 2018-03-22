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
	int				distance;
	struct s_link	*edges;
	struct s_node	*next;
	struct s_point	coord;
}					t_node;

typedef struct		s_ant
{
	int				pos;
	int				rank;
	struct s_ant	*next;
}					t_ant;

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
	int				opl;
	struct s_node	*graph;
}					t_lem;

/*
** ------------------------- PARSER -------------------------
*/
int					set_ant(t_lem *params);
int					set_start(char *line, t_lem *params, int *mod);
int					is_com(char *line);
int					set_room(char *line, t_lem *params, int *mod, t_node **gr);
int					set_end(char *line, t_lem *params, int *mod);
int					set_link(char *line, t_lem *params, t_node **node);
/*
** ------------------------- SOLVER -------------------------
*/
int					solver(t_lem *params, char *buf);
void				print_result(t_link *path, int len, t_lem *params);
void				free_params(t_lem *params);
/*
** ------------------------- GRAPH & ANTS -------------------------
*/
t_node				*create_node(int x, int y, char *name);
t_node				*pushback_node(t_node *start, t_node *new);
t_node				*free_node(t_node *node);
t_node				*fetch_node(t_node *node, char *name);
t_link				*enqueue(t_link *start, t_node *add, int dist);
t_link				*dequeue(t_link *element);
int					free_queue(t_link *queue);
t_ant				*create_ant(int rank);
t_ant				*pushback_ant(t_ant *start, t_ant *new);
t_ant				*search_and_destroy(t_ant *ant_list);
/*
** ------------------------- UTILITIES -------------------------
*/
void				print_nodes(t_lem *params);
void				print_optimal_path(t_link *path, int len);

#endif
