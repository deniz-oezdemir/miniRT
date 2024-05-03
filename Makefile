# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 22:25:40 by denizozd          #+#    #+#              #
#    Updated: 2024/05/03 13:56:50 by denizozd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ##add name
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPATH = ./libft

SRCS = ##add source files

OBJS = $(SRCS:.c=.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(NAME)

makelibft:
	make -C $(LIBFTPATH)
	cp $(LIBFTPATH)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	make -C $(MLX_LIB)
	$(CC) $(OBJS) -L./libft -lft $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $^ -o $@

clean:
	rm -f $(OBJS)
	cd $(LIBFTPATH) && make clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_LIB)
	cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: all clean fclean re libft
