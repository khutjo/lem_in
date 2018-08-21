/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:46:19 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 16:26:26 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*hold;
	unsigned char	c_c;
	size_t			index;

	c_c = (unsigned char)c;
	hold = (unsigned char *)b;
	index = -1;
	while (++index < len)
		hold[index] = c_c;
	return (b);
}
