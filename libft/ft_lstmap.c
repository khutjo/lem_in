/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:41:18 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/13 09:48:32 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *read;
	t_list *hold;
	t_list *new;

	if (!lst)
		return (NULL);
	read = lst->next;
	hold = NULL;
	new = NULL;
	if ((new = (t_list *)malloc(sizeof(t_list))))
	{
		hold = ft_lstmap(read, f);
		new = f(lst);
		new->next = hold;
	}
	return (new);
}
