/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:20:31 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/15 10:40:30 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrf(char *s, char c, int side)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
	{
		if (side == 'a')
			new = ft_strdup(&s[++i]);
		if (side == 'b')
			new = ft_strdup(&s[--i]);
		if (side == 'o')
			new = ft_strdup(&s[i]);
		return (new);
	}
	return (NULL);
}
