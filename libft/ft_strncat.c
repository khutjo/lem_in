/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:34:42 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:00:00 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	index1;
	size_t	index;

	index = 0;
	index1 = 0;
	while (dst[index] != '\0')
		index++;
	while (index1 < n && src[index1] != '\0')
	{
		dst[index] = src[index1];
		index++;
		index1++;
	}
	dst[index] = '\0';
	return (dst);
}
