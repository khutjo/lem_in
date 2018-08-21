/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:27:06 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/16 16:49:38 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	flag(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static	int	no_space(char *s, int index, int end)
{
	while (flag(s[index]))
	{
		if (end == 1)
			index++;
		else
			index--;
		if ((s[index] == '\0' && end == 1) || (index == -1))
			return (-1);
	}
	return (index);
}

char		*ft_strtrim(char const *s)
{
	int		index;
	int		s_big;
	int		s_end;
	char	*hold;

	hold = 0;
	index = 0;
	if (!s)
		return (NULL);
	s_end = 1 + no_space((char*)s, -1 + ft_strlen(s), 0);
	s_big = no_space((char*)s, 0, 1);
	if (s_big == -1)
	{
		s_big = 0;
		s_end = 0;
	}
	if ((hold = (char *)malloc(sizeof(char) * 1 + (s_end - s_big))))
	{
		while (s_big < s_end)
			hold[index++] = s[s_big++];
		hold[index] = '\0';
	}
	return (hold);
}
