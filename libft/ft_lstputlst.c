/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 09:51:30 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/15 10:18:50 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputlst(t_list **head)
{
	t_list	*hold;

	hold = (*head);
	while (hold != NULL)
	{
		if (hold->content != NULL)
			ft_lstputstr(hold);
		hold = hold->next;
	}
}
