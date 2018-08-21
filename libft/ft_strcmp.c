/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:27:39 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/01 14:58:34 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				index;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	index = 0;
	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	while (c_s1[index] == c_s2[index] && \
			c_s1[index] != '\0' && c_s2[index] != '\0')
		index++;
	index = c_s1[index] - c_s2[index];
	return (index);
}
