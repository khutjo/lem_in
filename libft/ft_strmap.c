/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:07:13 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/16 16:00:59 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*hold;

	if (!s || !f)
		return (NULL);
	index = -1;
	hold = 0;
	if ((hold = ft_strnew(ft_strlen(s))))
	{
		while (s[++index] != '\0')
			hold[index] = f(s[index]);
	}
	return (hold);
}
