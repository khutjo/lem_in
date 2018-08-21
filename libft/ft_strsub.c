/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:03:12 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:09:58 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*hold;
	size_t	index;

	hold = 0;
	index = len;
	if (!s)
		return (0);
	if ((hold = (char *)malloc(sizeof(char) * 1 + index)))
	{
		index = 0;
		while (s[start] != '\0')
		{
			hold[index] = s[start];
			index++;
			start++;
		}
		hold[len] = '\0';
	}
	return (hold);
}
