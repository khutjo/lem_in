/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heretohere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 08:21:18 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/15 10:19:28 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2)
{
	char *rtn;

	rtn = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if ((rtn = (char *)malloc(sizeof(char) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		ft_strcpy(rtn, s1);
		ft_strcat(rtn, s2);
	}
	return (rtn);
}
