# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agilles <agilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:34:53 by agilles           #+#    #+#              #
#    Updated: 2024/03/25 17:56:59 by agilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FTL_LIB = ftl_lib.a
LIBFT = printf_libft/libftprintf.a
CC = gcc -Werror -Wall -Wextra -O3 -march=native -flto -fno-signed-zeros -funroll-loops
SRC =	fractol.c\
		utils.c\
		color.c\
		input.c\
		init.c\



MAIN = main.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $$(dirname $(LIBFT))

fclean: clean
	@$(MAKE) fclean -C $$(dirname $(LIBFT))
	@rm -f $(NAME)
	@rm -f $(FTL_LIB)

re: fclean all

%.o : %.c
	$(CC) -g -Imlx -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $$(dirname $@)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(FTL_LIB)
	ar rcs $(FTL_LIB) $(OBJ)
	$(CC) $(OBJ) $(MAIN) $(FTL_LIB) mlx_linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

