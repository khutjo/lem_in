/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:44:18 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:27:21 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	numlen(long n, int *sign)
{
	int index;

	index = 0;
	if (n < 0)
	{
		n *= -1;
		index++;
		*sign = 1;
	}
	if (n == 0)
		index++;
	while (n > 0)
	{
		n /= 10;
		index++;
	}
	return (index);
}

char		*ft_itoa(int n)
{
	int		index;
	long	hold;
	int		sign;
	char	*num;

	num = 0;
	sign = 0;
	hold = (long)n;
	index = numlen(hold, &sign);
	if (n < 0)
		hold *= -1;
	if ((num = ft_memalloc(1 + index)))
	{
		num[index] = '\0';
		if (n == 0)
			num[0] = '0';
		while (--index > -1 && hold > 0)
		{
			num[index] = '0' + (hold % 10);
			hold /= 10;
		}
		if (sign == 1)
			num[0] = '-';
	}
	return (num);
}
