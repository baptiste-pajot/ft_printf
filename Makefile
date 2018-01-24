# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/24 07:44:51 by bpajot       #+#   ##    ##    #+#        #
#    Updated: 2018/01/24 07:44:54 by bpajot      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/21 14:37:00 by bpajot       #+#   ##    ##    #+#        #
#    Updated: 2018/01/24 07:38:47 by bpajot      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

TEST = test
NAME = libftprintf.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LFT_FLAGS = -L libft/ -lft
LIBS = libft/libft.a
PATH_SRCS = ./
PATH_OBJS = ./
PATH_INCS = ./
FILES = ft_printf.c ft_putwchar.c ft_putchar_size.c
MAIN_TEST = main_test.c
SRCS = $(addprefix $(PATH_SRCS), $(FILES))
OBJS = $(addprefix $(PATH_OBJS), $(FILES:.c=.o))
SRCS_TEST = $(addprefix $(PATH_SRCS), $(MAIN_TEST))
OBJS_TEST = $(addprefix $(PATH_OBJS), $(MAIN_TEST:.c=.o))
INCS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	@echo "CREATION DE LA LIBFTPRINTF.A "
	@ar rcs $@ $^
	@libtool -static -o $(NAME) $(NAME) $(LIBS)
	@echo "👍  COMPILATION REUSSIE 👍\ "

$(TEST): $(OBJS) $(OBJS_TEST)
	make -C libft
	@echo "CREATION DE L'EXECUTABLE TEST "
	@$(CC) $(CC_FLAGS) $(LFT_FLAGS) -o $@ $^
	@echo "👍  COMPILATION REUSSIE 👍\ "

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INCS)
	@echo "CREATION $@ "
	@$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "👍  COMPILATION REUSSIE 👍\ "

clean:
	make -C libft clean
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(OBJS_TEST)

fclean: clean
	make -C libft fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)

re: fclean all
