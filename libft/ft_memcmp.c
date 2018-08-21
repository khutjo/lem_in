/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:45:31 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 11:39:16 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	unsigned const char	*c_s1;
	unsigned const char	*c_s2;

	index = 0;
	c_s1 = (unsigned const char *)s1;
	c_s2 = (unsigned const char *)s2;
	while (index < n)
	{
		if (c_s1[index] != c_s2[index])
			return (c_s1[index] - c_s2[index]);
		index++;
	}
	return (0);
}
