/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_out_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:18:12 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/29 16:36:24 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

t_move	*last_node(t_move *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

int		repeat(t_map *map, t_move *pre_node, t_move *sender)
{
	while (pre_node != sender && pre_node->pre != map && map != pre_node->home)
		pre_node = pre_node->next;
	if (pre_node->pre == map || map == pre_node->home)
	{
		return (0);
	}
	return (1);
}

void	amende_end(t_move **hold, t_move **save, int *num_moves, int temp_move)
{
	if ((*hold)->next->exit && (temp_move < *num_moves || *num_moves == -1))
	{
		(*hold)->exit = 1;
		*num_moves = temp_move;
		if ((*save))
			free_dead_end(save);
		(*save) = (*hold)->next;
	}
	else
		free_dead_end(&(*hold)->next);
}

int		maze_runner(t_map *map, t_move *pre_node)
{
	int		i;
	t_move	*hold;
	t_move	*small_move;
	int		temp_move;
	int		num_moves;

	i = -1;
	small_move = NULL;
	hold = last_node(pre_node);
	num_moves = -1;
	(map->end ? hold->exit = 1 : 0);
	while (!map->end && map->tree[++i])
		if (repeat(map->tree[i], pre_node, hold))
		{
			hold->next = make_t_move(pre_node->home, map->tree[i], i, -1);
			temp_move = maze_runner(map->tree[i], pre_node);
			amende_end(&hold, &small_move, &num_moves, temp_move);
			hold->next = NULL;
		}
	hold->next = small_move;
	return (map->end ? 1 : ++num_moves);
}

void	find_end(t_map *map)
{
	int i;

	i = 0;
	if (map && map->end)
	{
		map->moves = NULL;
		map = map->next;
	}
	if (!map)
		return ;
	while (map->tree[i])
		i++;
	map->moves = (t_move **)malloc(sizeof(t_move *) * (1 + i));
	map->moves[i] = NULL;
	i = -1;
	while (map->tree[++i])
	{
		map->moves[i] = make_t_move(map, map->tree[i], i, 0);
		map->moves[i]->num_move = maze_runner(map->tree[i], map->moves[i]);
		if (!map->moves[i]->exit)
			map->moves[i]->num_move = -1;
	}
	if (map->next)
		find_end(map->next);
}
