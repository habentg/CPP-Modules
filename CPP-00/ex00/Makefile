# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 04:26:27 by hatesfam          #+#    #+#              #
#    Updated: 2023/12/27 09:54:01 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re