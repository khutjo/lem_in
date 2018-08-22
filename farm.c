/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:34:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/22 18:01:25 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"
#include <stdio.h>

int  main(void)
{
	int		i;
	t_ant	*temp_ant;
	t_map	*head;
	t_map	*temp_map;

	head = NULL;
	temp_ant = make_line();
	head = make_map_node(temp_ant);
	map(head, temp_ant);
	while (head)
	{
	i = 0;
		while (head->tree[i])
		{
			temp_map = head->tree[i++];
			printf("%s <> %s \n", head->name, temp_map->name);
		}
		printf("start = %d <==> end = %d <==> ant =  %d\n", head->start,\
				head->end, head->ants);
		head = head->next;
		printf("\n");
	}
	return (0);
}
