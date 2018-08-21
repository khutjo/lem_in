/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:08:39 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/16 16:48:15 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		index2;
	char	*hold;

	hold = NULL;
	if (!s1 || !s2)
		return (hold);
	index = ft_strlen(s1);
	index2 = ft_strlen(s2);
	if ((hold = (char *)malloc(sizeof(char) * 1 + (index + index2))))
	{
		hold = ft_strcpy(hold, s1);
		hold = ft_strcat(hold, s2);
	}
	return (hold);
}
