# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:15:07 by qmebble           #+#    #+#              #
#    Updated: 2019/02/16 16:39:17 by oargrave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = fillit.c ft_alco.c ft_dlc.c generic_map.c check_tetriminos.c
FLAGS = -Wall -Wextra -Werror
NAME = fillit

all: $(NAME)

$(NAME):
	@make --directory libft
	@gcc $(FLAGS) $(FILE) libft/libft.a -o $(NAME)

clean:
	@make --directory libft clean

fclean: clean
	@make --directory libft fclean
	@rm -f $(NAME)

re: fclean all
