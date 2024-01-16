# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 01:45:14 by hatesfam          #+#    #+#              #
#    Updated: 2024/01/15 11:21:52 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scaler

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

SRC = main.cpp ScalarConverter.cpp InputType.cpp printer.cpp
OBJDIR = obj
OBJ_FILES = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $@
	
clean: $(OBJDIR)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean phony re	