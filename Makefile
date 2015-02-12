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

NAME			=	libftprintf.a

SRC_DIR			=	srcs
INCLUDE_DIR		=	includes
OBJ_DIR			=	objs

LIB_DIR			=	libft
LIB_SRC_DIR		=	srcs
LIB_INCLUDE_DIR	=	includes

LIB_SRC			=	ft_memset.c				\
					ft_bzero.c				\
					ft_memcpy.c				\
					ft_memccpy.c			\
					ft_memmove.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_strlen.c				\
					ft_strdup.c				\
					ft_strcpy.c				\
					ft_strncpy.c			\
					ft_strcat.c				\
					ft_strncat.c			\
					ft_strlcat.c			\
					ft_strcmp.c				\
					ft_strncmp.c			\
					ft_strstr.c				\
					ft_strnstr.c			\
					ft_atoi.c				\
					ft_atoi_base.c			\
					ft_strchr.c				\
					ft_strrchr.c			\
					ft_isalpha.c			\
					ft_isdigit.c			\
					ft_isalnum.c			\
					ft_isascii.c			\
					ft_isprint.c			\
					ft_toupper.c			\
					ft_tolower.c			\
					ft_putchar.c			\
					ft_putstr.c				\
					ft_putendl.c			\
					ft_putnbr.c				\
					ft_putchar_fd.c			\
					ft_putstr_fd.c			\
					ft_putendl_fd.c			\
					ft_putnbr_fd.c			\
					ft_memalloc.c			\
					ft_memdel.c				\
					ft_strnew.c				\
					ft_strdel.c				\
					ft_strclr.c				\
					ft_striter.c			\
					ft_striteri.c			\
					ft_itoa.c				\
					ft_ltoa.c				\
					ft_ltoa_base.c			\
					ft_strmap.c				\
					ft_strmapi.c			\
					ft_strequ.c				\
					ft_strnequ.c			\
					ft_strjoin.c			\
					ft_strsplit.c			\
					ft_strsub.c				\
					ft_strtrim.c			\
					ft_lstnew.c				\
					ft_lstadd.c				\
					ft_lstiter.c			\
					ft_lstdelone.c			\
					ft_lstdel.c				\
					ft_strccheck.c			\
					ft_setcolor.c			\
					ft_resetcolor.c			\
					ft_strclen.c			\
					ft_lstrev.c				\
					ft_lstpushback.c		\
					ft_str_split.c			\
					ft_lstsize.c			\
					ft_strsublen.c			\
					ft_utoa.c				\
					ft_utoa_base.c			\
					ft_ultoa.c				\
					ft_recursive_power.c	\
					ft_itoa_base.c			\
					ft_tablen.c				\
					ft_strunion.c			\
					ft_free_tab.c			\
					ft_lstd_new.c			\
					ft_lstd_add.c			\
					ft_lstd_pushback.c		\
					ft_lstd_size.c			\
					ft_lstd_foreach.c		\
					ft_lstd_delone.c		\
					ft_get_maxsize.c		\
					ft_lst_foreach.c		\
					ft_tab_foreach.c		\
					ft_free_lst.c			\
					ft_strccount.c			\
					ft_btree_new.c			\
					ft_btree_insert.c		\
					ft_btree_del.c			\
					ft_btree_find.c			\
					ft_btree_delone.c		\
					ft_lstmap.c				\
					get_next_line.c

SRC				=	$(LIB_SRC)							\
					printf.c							\
					read_format.c						\
					format_tools_sSdDp.c				\
					format_tools_ioOuU.c				\
					format_tools_perxXcC.c				\
					parser.c							\
					parser_tools.c						\
					display.c							\
					scases_handler.c					\
					number_handling.c					\

OBJ				=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

COMPILER		=	gcc
CFLAGS			=	-c -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIB_DIR)/$(LIB_INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/$(LIB_SRC_DIR)/%.c
	@$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fcleanlib:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

moulitest: fclean fcleanlib
	@sed -i ''  s,LOL,`pwd`, moulitest/config.ini
	@$(MAKE) -C moulitest ft_printf
	@sed -i ''  s,`pwd`,LOL, moulitest/config.ini
	./moulitest/ft_printf_tests/ft_printf_test

test: cclean
	@$(MAKE) -C tests
	./tests/tests

cclean: fclean fcleanlib
	@$(MAKE) -C tests fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all
