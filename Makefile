# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 08:43:18 by kmaputla          #+#    #+#              #
#    Updated: 2018/08/29 15:15:03 by kmaputla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -g -Wall -Wextra -Werror -o run ants_roll_out.c farm.c protection.c utility_funcs.c map_out_route.c  get_list.c make_links.c libft/libft.a
