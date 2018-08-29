/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:37:16 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/28 17:56:27 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSECT_LIB_H
# define INSECT_LIB_H
# include "./libft/libft.h"

typedef	struct		s_map
{
	int				end;
	int				start;
	int				ants;
	int				best;
	char			*name;
	struct s_move	**moves;
	struct s_map	**tree;
	struct s_map	*next;
}					t_map;

typedef struct		s_move
{
	int				exit;
	int				route_name;
	int				num_move;
	struct s_map	*pre;
	struct s_map	*home;
	struct s_move	*next;
}					t_move;

typedef struct		s_ants
{
	int				name;
	struct s_map	*home;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_ant
{
	int				max;
	char			*line;
	struct s_ant	*next;
}					t_ant;

void				no(void);
void				find_end(t_map *map);
t_ant				*make_line(void);
void				best_route(t_map *head);
int					is_it_cool(t_ant *lines);
void				free_lines(t_ant **lines);
t_map				*make_map_node(t_ant *line);
void				free_dead_end(t_move **node);
void				free_joogle_maps(t_map **map);
void				map(t_map *head, t_ant *lines);
void				set_the_queen_free(t_ants **queen);
void				ants_roll_out(t_ants *queen, t_map *head);
void				lay_ant_eggs(t_map *head, t_ants **queen_ant);
t_move				*make_t_move(t_map *home, t_map *pre, int route, int\
		moves);
#endif
