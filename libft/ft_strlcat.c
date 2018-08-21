/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:33:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/09 12:58:31 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = ft_strlen(dst);
	if (index > dstsize)
		return (ft_strlen(src) + dstsize);
	if (index < dstsize)
		ft_strncat(dst + index, (char *)src, dstsize - index - 1);
	return (index + ft_strlen(src));
}
