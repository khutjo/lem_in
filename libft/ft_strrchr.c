/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:35:26 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:04:14 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*hold;
	char	c_c;

	index = 0;
	hold = 0;
	c_c = (char)c;
	while (s[index] != '\0')
		index++;
	while (s[index] != c_c && index >= 0)
		index--;
	if (s[index] == c)
		hold = (char *)&s[index];
	return (hold);
}
