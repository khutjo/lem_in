/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:45:08 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 11:32:50 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			index;
	unsigned char	*c_dst;
	unsigned char	*c_src;
	unsigned char	c_c;

	index = 0;
	c_c = (unsigned char)c;
	c_src = (unsigned char *)src;
	c_dst = (unsigned char *)dst;
	while (index < len)
	{
		c_dst[index] = c_src[index];
		if (c_src[index] == c_c)
			return (&c_dst[++index]);
		index++;
	}
	return (0);
}
