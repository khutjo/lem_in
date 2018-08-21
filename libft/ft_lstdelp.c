/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 08:52:22 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/15 09:46:09 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstdelp(t_list **alst, int place)
{
	int		i;
	t_list	*hold;
	t_list	*pri;

	i = 0;
	pri = (*alst);
	hold = (*alst);
	while (i < place)
	{
		pri = hold;
		hold = hold->next;
		i++;
	}
	if (i == place)
	{
		if (place == 0)
			*alst = (*alst)->next;
		else
			pri->next = hold->next;
		free(hold);
		hold = NULL;
		return (1);
	}
	return (0);
}
