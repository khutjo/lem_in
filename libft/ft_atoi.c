/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:42:57 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/07 16:14:30 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	check(char *str)
{
	int		i;
	int		sk;
	char	*skip;

	i = -1;
	sk = 0;
	skip = "\t\v\f\r\n ";
	while (++i < 7)
		if (str[sk] == skip[i])
		{
			sk++;
			i = -1;
		}
	return (sk);
}

int			ft_atoi(const char *str)
{
	int		index;
	long	num;
	int		sign;

	num = 0;
	sign = 0;
	index = check((char *)str);
	if (str[index] == '-' || str[index] == '+')
		sign = str[index++];
	while (str[index] >= '0' && str[index] <= '9')
	{
		num *= 10;
		num += str[index] - '0';
		index++;
		if (num < 0 && sign == '-')
			return (0);
		else if (num < 0)
			return (-1);
	}
	if (sign == '-')
		num *= -1;
	return ((int)num);
}
