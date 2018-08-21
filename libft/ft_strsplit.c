/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:03:37 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/04 08:43:08 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		skip(char const *s, char c, int place, int state)
{
	if (state == 0)
		while (s[place] != c && s[place] != '\0')
			place++;
	if (state == 1)
		while (s[place] == c && s[place] != '\0')
			place++;
	return (place);
}

int				num_of_words(char const *s, char c)
{
	int count;
	int index;

	count = 0;
	index = 0;
	index = skip(s, c, index, 1);
	while (s[index])
	{
		if (s[index] != c)
			count++;
		index = skip(s, c, index, 0);
		index = skip(s, c, index, 1);
	}
	return (count);
}

static	char	**make(char const *s, char c)
{
	int		len;
	int		count;
	int		index;
	int		keep;
	char	**hold;

	index = 0;
	count = 0;
	hold = NULL;
	len = num_of_words(s, c);
	if (len != 0 && (hold = (char **)malloc(sizeof(char **) * (1 + len))))
	{
		hold[len] = NULL;
		while (s[index] != '\0')
		{
			index = skip(s, c, index, 1);
			while (s[++index] != c && s[index] != '\0')
				keep++;
			if ((hold[count] = (char *)malloc(sizeof(char*) * (1 + keep))))
				hold[count++][keep] = '\0';
			keep = 0;
			index = skip(s, c, index, 1);
		}
	}
	return (hold);
}

static	char	**nothing(void)
{
	char **hold;

	hold = NULL;
	if ((hold = (char **)malloc(sizeof(char **) * 1)))
	{
		hold[0] = NULL;
	}
	return (hold);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**hold;
	int		index;
	int		keep;
	int		count;

	index = 0;
	keep = 0;
	count = 0;
	hold = NULL;
	if (!s)
		return (hold);
	if (!(hold = make(s, c)))
		return (nothing());
	index = skip(s, c, index, 1);
	while (s[index] != '\0')
	{
		while (s[index] != c && s[index] != '\0')
			hold[keep][count++] = s[index++];
		hold[keep++][count] = '\0';
		count = 0;
		index = skip(s, c, index, 1);
	}
	return (hold);
}
