# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:33:38 by jlange            #+#    #+#              #
#    Updated: 2017/05/24 11:14:49 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all, clean, fclean, re

SRC_PATH = src

OBJ_PATH = obj

NAME = fractol.a

NAME_BIS = fractol

CC = gcc

HEADER = include/fractol.h

CFLAGS = -g -Wall -Wextra -Werror

CPPFLAGS = -Iinclude -ImlxSierra

SRC_NAME =  main.c					\
			tools.c					\
			julia.c					\
			mandelbrot.c			\
			mandelbar.c				\
			tapis.c					\
			burningship.c			\
			buddha.c				\
			display_hook.c			\
			text.c					\
			colors.c				\
			mouse.c					\
			zoom.c					\
			calc_pow.c				\
			tools2.c				\

OBJ = $(SRC_NAME:.c=.o)

OBJ_LIB_NAME = $(addprefix obj/, $(OBJ))

NB_FILES = 15

all: $(NAME)

$(NAME): obj/ $(HEADER) $(OBJ_LIB_NAME)
	@rm nb.txt && tput cnorm
	@printf " ✅\n\033[0m"
	@printf "\033[1;36mCreating library\033[0m"
	@ar rc $(NAME) $(OBJ_LIB_NAME)
	@printf " ✅\n"
	@printf "\033[1;36mIncrease the search speed\033[0m"
	@ranlib $(NAME)
	@printf " ✅\n\n"
	@$(CC) $(NAME) libft/libft.a mlxCapitan/libmlx.a -framework OpenGl -framework AppKit -o $(NAME_BIS)

obj/:
	@make -C libft
	@printf "\n\033[38;5;46m==| FRACTOL Makefile |==\033[0m\n"
	@mkdir $(OBJ_PATH) 2> /dev/null
	@touch nb.txt
	@echo 0 > nb.txt
	@echo "\033[1;36mCompiling .o progress : \033[0m"

obj/%.o: src/%.c
	@test=`cat nb.txt`; test=`echo $$test + 1 | bc`; sh loading_bar.sh $(NB_FILES) $$test; echo $$test > nb.txt
	@$(CC) -o $@ $(CPPFLAGS) -c $? $(CFLAGS)

clean:
	@make clean -C libft
	@printf "\n\033[1;31mDeleting FRACTOL all .o\033[0m\n"
	@rm -rf $(OBJ_PATH)
	@printf "\033[1;32mThe folder is clean ✅\033[0m\n\n"

fclean:
	@make fclean -C libft
	@printf "\n\033[1;31mDeleting FRACTOL Library.a and all .o\033[0m\n"
	@rm -rf $(NAME) $(OBJ_PATH) $(NAME_BIS)
	@printf "\033[1;32mThe folder is clean ✅\033[0m\n\n"

re: fclean all
