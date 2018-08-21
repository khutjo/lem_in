/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:28:22 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 16:25:44 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		index;

	index = -1;
	dup = 0;
	if ((dup = (char *)malloc(sizeof(char) * 1 + ft_strlen(s))))
	{
		while (s[++index] != '\0')
			dup[index] = (char)s[index];
		dup[index] = '\0';
	}
	return (dup);
}
