/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:45:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/14 17:23:00 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long hold;
	char num;

	hold = n;
	num = 0;
	if (hold < 0)
	{
		hold *= -1;
		ft_putchar_fd('-', fd);
	}
	num = '0' + (hold % 10);
	hold /= 10;
	if (hold > 0)
		ft_putnbr_fd(hold, fd);
	ft_putchar_fd(num, fd);
}
