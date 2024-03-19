# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agilles <agilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:34:53 by agilles           #+#    #+#              #
#    Updated: 2024/03/19 17:38:18 by agilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = printf_libft/libftprintf.a
CC = gcc -Werror -Wall -Wextra -O3 -march=native -flto -fno-signed-zeros -funroll-loops
SRC =	fractol.c\
		utils.c\
		\



MAIN = main.c\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -g -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) mlx_linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

