# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 18:06:22 by hatesfam          #+#    #+#              #
#    Updated: 2024/01/30 15:59:35 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
# RM = rm -f

SRC = main.cpp RPN.cpp helpers.cpp
OBJ = obj

OBJ_FILES = $(addprefix $(OBJ)/, $(SRC:.cpp=.o))

$(OBJ)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(FLAGS) $(OBJ_FILES) -o $@

clean: $(OBJ)
	$(RM)r $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean all clean
	
