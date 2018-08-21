/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:17:10 by kmaputla          #+#    #+#             */
/*   Updated: 2018/05/31 16:52:28 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (del)(void *, size_t))
{
	t_list *hold;

	hold = (*alst);
	if (hold != NULL)
	{
		*alst = (*alst)->next;
		ft_lstdel(alst, del);
		del(hold->content, hold->content_size);
		free(hold);
	}
	alst = NULL;
}
