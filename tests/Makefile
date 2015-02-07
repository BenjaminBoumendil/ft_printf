#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 16:09:20 by bboumend          #+#    #+#              #
#    Updated: 2014/02/10 22:07:28 by bboumend         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		tests

SRC			=		main.cpp

OBJ_DIR		=		objs
OBJ			=		$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

COMPILER	=		g++
FLAG_COMP	=		-Wall -Wextra -Werror -Wno-format -O3 -std=c++1y

LIB_DIR		=		../.
LIB_NAME	=		libftprintf.a
FLAG_LINK	=		-L$(LIB_DIR) -lftprintf

STAR		=		**********

all:
	@echo "\n\033[36m $(STAR) [Compiling: $(NAME)] $(STAR) \033[0m"
	@$(MAKE) $(LIB_DIR)/$(LIB_NAME)
	@$(MAKE) $(NAME)

$(LIB_DIR)/$(LIB_NAME):
	@(cd $(LIB_DIR) && $(MAKE))

$(NAME): $(OBJ)
	$(COMPILER) $^ -o $@ $(FLAG_LINK)
	@echo "\033[32m $(STAR) [Done: $(NAME)] $(STAR) \033[0m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.cpp
	@$(COMPILER) -c $(FLAG_COMP) $^ -o $@

fcleanlib:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

clean:
	@echo "\n\033[35m $(STAR) [Cleaning: $(NAME)] $(STAR) \033[0m"
	@rm -f $(OBJ)
	@rm -df $(OBJ_DIR)

fclean: clean fcleanlib
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
