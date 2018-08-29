/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:34:52 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/29 16:38:28 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

void	free_dead_end(t_move **node)
{
	if ((*node)->next)
		free_dead_end(&(*node)->next);
	free((*node));
}

void	free_lines(t_ant **lines)
{
	if ((*lines)->next)
		free_lines(&(*lines)->next);
	free((*lines)->line);
	free((*lines));
}

void	free_joogle_maps(t_map **map)
{
	int i;

	i = -1;
	if ((*map)->next)
		free_joogle_maps(&(*map)->next);
	while ((*map)->moves && (*map)->tree[++i])
		free_dead_end(&(*map)->moves[i]);
	free((*map)->moves);
	free((*map)->tree);
	free((*map)->name);
	free((*map));
}

void	set_the_queen_free(t_ants **queen)
{
	if ((*queen)->next)
		set_the_queen_free(&(*queen)->next);
	free((*queen));
}

t_move	*make_t_move(t_map *home, t_map *pre, int route, int moves)
{
	t_move	*temp;

	temp = (t_move *)malloc(sizeof(t_move));
	temp->exit = 0;
	temp->pre = pre;
	temp->home = home;
	temp->num_move = moves;
	temp->route_name = route;
	temp->next = NULL;
	return (temp);
}
