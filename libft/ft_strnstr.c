/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:20:11 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:02:42 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	handler(const char *str1, const char *str2, int hold, int len)
{
	int index;

	index = 0;
	while (str1[hold] == str2[index] && str1[hold] && hold < len)
	{
		hold++;
		index++;
	}
	if (str2[index] == '\0')
	{
		return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		exit_kick;
	size_t	index;
	char	*pointer;

	index = 0;
	exit_kick = 0;
	pointer = 0;
	if (needle[index] == '\0')
		return ((char *)haystack);
	while (haystack[index] != '\0' && exit_kick == 0 && index < len)
	{
		if (haystack[index] == needle[0])
		{
			if (handler(haystack, needle, index, len))
			{
				pointer = (char*)&haystack[index];
				exit_kick = 1;
			}
		}
		index++;
	}
	return (pointer);
}
