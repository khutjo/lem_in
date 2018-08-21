/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:46:05 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 16:09:40 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*c_src;
	unsigned char	*c_dst;

	index = -1;
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (&c_dst[0] > &c_src[0])
	{
		while (len > 0)
		{
			len--;
			c_dst[len] = c_src[len];
		}
	}
	else
		while (++index < len)
			c_dst[index] = c_src[index];
	return (dst);
}
