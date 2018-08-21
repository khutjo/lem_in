/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:45:19 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 11:38:07 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char chold;
	unsigned char *shold;

	shold = (unsigned char *)s;
	chold = (unsigned char)c;
	while (n--)
	{
		if (*shold == chold)
			return (shold);
		shold++;
	}
	return (NULL);
}
