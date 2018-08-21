/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:37:16 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/21 18:04:46 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSECT_LIB_H
# define INSECT_LIB_H
# include "./libft/libft.h"

typedef	struct		s_map
{
	char			*name;
	struct s_map	**tree;
	struct s_map	*next;
}					t_map;

typedef struct		s_ant
{
	int				max;
	char			*line;
	struct s_ant	*next;
}					t_ant;

t_ant				*make_line(void);
t_map				*make_map_node(t_ant *line);

#endif
