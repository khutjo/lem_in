# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 08:43:18 by kmaputla          #+#    #+#              #
#    Updated: 2018/09/07 10:15:55 by kmaputla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB=./libft/libft.a

NAME=lem-in

SRC=ants_roll_out.c\
   	farm.c\
   	protection.c\
   	utility_funcs.c\
   	map_out_route.c\
  	get_list.c\
   	make_links.c\

all:$(NAME)

$(NAME):$(LIB)
	@gcc -g -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIB)
	@echo "done!"

$(LIB):
	@make -C ./libft

clean:
	@make clean -C ./libft
	@echo "cleaning"

fclean:
	@make fclean -C ./libft
	@rm $(NAME)
	@echo "full clean!"

re:fclean all

