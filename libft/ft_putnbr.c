/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:28:30 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:25:30 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		index;
	long	hold;

	hold = (long)n;
	index = 0;
	if (hold < 0)
	{
		hold *= -1;
		ft_putchar('-');
	}
	index = hold % 10;
	hold /= 10;
	index += '0';
	if (hold > 0)
		ft_putnbr(hold);
	write(1, &index, 1);
}
