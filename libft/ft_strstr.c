/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:35:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:03:13 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handler(char *str1, char *str2, int hold)
{
	int index;

	index = -1;
	while (str1[hold] == str2[++index] && str1[hold])
		hold++;
	if (str2[index] == '\0')
		return (1);
	return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		index;

	index = 0;
	if (needle[index] == '\0')
		return ((char*)haystack);
	while (haystack[index] != '\0')
	{
		if (haystack[index] == needle[0])
		{
			if (handler((char *)haystack, (char *)needle, index))
				return ((char *)&haystack[index]);
		}
		index++;
	}
	return (0);
}
