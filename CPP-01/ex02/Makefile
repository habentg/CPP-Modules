# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 09:49:32 by hatesfam          #+#    #+#              #
#    Updated: 2023/12/27 10:05:15 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) main.cpp -o $(NAME)

clean:
	
fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re