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

NAME		=		my_test

LIB_DIR		=		../.

LIB_NAME	=		libftprintf.a

INCLUDE_DIR	=

SRC_DIR		=

SRC			=		main.c

OBJ			=		$(SRC:.c=.o)

FLAG_LINK	=		-L$(LIB_DIR) -lftprintf

FLAG_COMP	=		-Wall -Wextra -Werror -Wno-format

STAR		=		**********

all:
	@echo "\n\033[36m $(STAR) [Compiling: $(NAME)] $(STAR) \033[0m"
	@$(MAKE) $(LIB_DIR)/$(LIB_NAME)
	@$(MAKE) $(NAME)

$(LIB_DIR)/$(LIB_NAME):
	@(cd $(LIB_DIR) && $(MAKE))

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(FLAG_LINK)
	@echo "\033[32m $(STAR) [Done: $(NAME)] $(STAR) \033[0m"

%.o: %.c
	@gcc -c $(FLAG_COMP) $^

clean:
	@echo "\n\033[35m $(STAR) [Cleaning: $(NAME)] $(STAR) \033[0m"
	@rm -f $(OBJ)

fcleanlib:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

fclean: clean fcleanlib
	@rm -f $(NAME)

re:
	@$(MAKE) fcleanlib
	@$(MAKE) fclean
	@$(MAKE) all
