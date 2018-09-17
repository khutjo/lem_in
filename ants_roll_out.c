/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_roll_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:24:56 by kmaputla          #+#    #+#             */
/*   Updated: 2018/09/07 10:47:15 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

void	print_out(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

int		im_i_done(t_ants *queen)
{
	while (queen && queen->home && queen->home->pre->end)
		queen = queen->next;
	if (queen)
		return (1);
	return (0);
}

int		is_duplicate(t_ants *queen, t_move *route)
{
	int	i;

	i = 0;
	while (queen)
	{
		if (queen->home && queen->home == route && !route->pre->end)
			i++;
		queen = queen->next;
	}
	if (i > 0)
		return (0);
	return (1);
}

void	start_to_end(t_ants *ants, t_move *route)
{
	while (ants)
	{
		print_out(ants->name, route->pre->name);
		ft_putchar('\n');
		ants = ants->next;
	}
}

void	ants_roll_out(t_ants *queen, t_move *route)
{
	t_ants	*ants;

	if (!route->pre->end)
		while (im_i_done(queen))
		{
			ants = queen;
			while (ants)
			{
				if (!ants->home && is_duplicate(queen, route))
				{
					ants->home = route;
					print_out(ants->name, ants->home->pre->name);
				}
				else if (ants->home && ants->home->next && \
						is_duplicate(queen, ants->home->next))
				{
					ants->home = ants->home->next;
					print_out(ants->name, ants->home->pre->name);
				}
				ants = ants->next;
			}
			ft_putchar('\n');
		}
	else
		start_to_end(queen, route);
}
