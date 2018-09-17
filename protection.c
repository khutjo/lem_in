/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:01:34 by kmaputla          #+#    #+#             */
/*   Updated: 2018/09/07 16:09:00 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

void	no(void)
{
	ft_putstr("Error");
	exit(0);
}

void	run_test(t_ant *lines)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;

	temp1 = NULL;
	temp2 = NULL;
	temp3 = NULL;
	if (lines->line[0] != '#')
	{
		(!(temp1 = ft_strchr(lines->line, ' ')) ? no() : 0);
		(!(temp2 = ft_strchr(++temp1, ' ')) ? no() : 0);
		(ft_strchr(++temp2, ' ') ? no() : 0);
		while (ft_isdigit(*temp1))
			temp1++;
		while (ft_isdigit(*temp2))
			temp2++;
		if (*temp1 != ' ' || *temp2 != '\0')
			no();
	}
}

void	start_and_end(t_ant *line1, t_ant *line2)
{
	while (line1 && !ft_strstr(line1->line, "##end"))
		line1 = line1->next;
	while (line2 && !ft_strstr(line2->line, "##start"))
		line2 = line2->next;
	if (line1 && line1->next && ft_strstr(line1->line, "##end"))
		run_test(line1->next);
	if (line2 && line2->next && ft_strstr(line2->line, "##start"))
		run_test(line2->next);
	if (!line1 || !line2)
		no();
}

void	are_there_rooms(t_ant *lines)
{
	run_test(lines);
	if (ft_strchr(lines->next->line, '-') == NULL && lines->next)
		are_there_rooms(lines->next);
}

int		is_it_cool(t_ant *lines)
{
	char	*char_num;
	t_ant	*run;

	char_num = NULL;
	while (lines->line[0] == '#')
		lines = lines->next;
	char_num = ft_itoa(ft_atoi(lines->line));
	if (!ft_strequ(char_num, lines->line))
		no();
	free(char_num);
	if (!lines->next)
		no();
	run = lines;
	while (run && !ft_strchr(run->line, '-'))
		run = run->next;
	(!run || ft_strchr(run->line, ' ') ? no() : 0);
	are_there_rooms(lines->next);
	start_and_end(lines, lines);
	return (1);
}
