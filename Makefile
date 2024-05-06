# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 22:25:40 by denizozd          #+#    #+#              #
#    Updated: 2024/05/06 11:29:57 by denizozd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
LIBFTNAME = libft.a
CC = cc
CFLAGS = ##-Wall -Wextra -Werror
LIBFTPATH = ./lib/libft

SRCS = src/main.c src/init.c src/cleaning.c src/parsing/parser.c src/parsing/ambient_light.c ##$(wildcard *.c)

OBJS = $(SRCS:.c=.o)
MLX_LIB = lib/mlx/
MLX_FLAGS = -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

makelibft:
	make -C $(LIBFTPATH)
	cp $(LIBFTPATH) $(LIBFTNAME)
	mv $(LIBFTNAME) $(NAME)

$(NAME): $(OBJS)
	@if [ ! -f $(LIBFTPATH)/libft.a ]; then \
 		echo "Building libft..."; \
		make -C $(LIBFTPATH); \
	else \
		echo "libft.a already exists."; \
	fi
	if [ ! -d "./lib/mlx" ]; then \
	git submodule add https://github.com/42Paris/minilibx-linux.git lib/mlx; \
	fi
	make -C $(MLX_LIB)
	$(CC) $(OBJS) -Llib/libft -lft $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	cd $(LIBFTPATH) && make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)/*.a
	cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: all clean fclean re libft
