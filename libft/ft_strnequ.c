/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:59:02 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 16:27:42 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((s1 && !s2) || (s2 && !s1))
		return (0);
	if (!s1 && !s2)
		return (1);
	if (!ft_strncmp((char *)s1, s2, n))
		return (1);
	return (0);
}
