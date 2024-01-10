# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 03:25:29 by hatesfam          #+#    #+#              #
#    Updated: 2024/01/10 04:02:13 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

SRC		= main.cpp Bureaucrat.cpp
OBJDIR	= obj
OBJ_FILES = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

clean: $(OBJDIR)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean phony re	
