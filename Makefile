# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 22:25:40 by denizozd          #+#    #+#              #
#    Updated: 2024/06/20 17:56:03 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main executable
NAME = miniRT
# Test executable
TEST_EXECUTABLE = test_minirt
# Get the operative system name
OS := $(shell uname)

# Compilation options
CC = cc #change back to cc
CFLAGS = -g -O0 -Wall -Wextra -Werror

# Libft library
LIBFT_PATH = lib/libft
LIBFT_FLAGS = -Llib/libft -lft

# MLX library
MLX_PATH = lib/mlx
MLX_FLAGS = -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDE = -I/usr/include -Imlx_linux

ifeq ($(UNAME), Darwin)
    INCLUDE = -I /usr/X11/include
endif

# Source files directory
SRCDIR = src
# Test files directory
TESTDIR = tests
# Object files directory
OBJDIR = obj

INCLUDE = -I/usr/include -Ilib/mlx

ifeq ($(OS), Darwin)
    INCLUDE = -I/usr/X11/include
    MLX_FLAGS = -L/usr/X11/lib -lX11 -lmlx -lXext
endif

# Source files (excluding main.c and test files)
SRC = $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)
SRC := $(filter-out $(SRCDIR)/main.c, $(SRC))
SRC := $(filter-out $(wildcard $(TESTDIR)/*.c), $(SRC))

# Excluded source files
EXCLUDED_SRC = $(SRCDIR)/main.c
# Excluded test files
EXCLUDED_TEST = $(wildcard $(TESTDIR)/*.c)

# Object files
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Object files for excluded source files
EXCLUDED_SRC_OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(EXCLUDED_SRC))
# Object files for excluded source files
EXCLUDED_TEST_OBJ = $(patsubst $(TESTDIR)/%.c, $(OBJDIR)/%.o, $(EXCLUDED_TEST))

# Color and styles
COLOR_RESET = \033[0m
BOLD_GREEN = \033[1;32m
GREEN = \033[0;32m
RED = \033[0;31m
HIDE = @

all: dependencies $(NAME)

test: dependencies $(TEST_EXECUTABLE)

dependencies:
	@echo "$(GREEN)Checking dependencies...$(COLOR_RESET)"
    # Check if mlx has been downloaded
    ifeq ($(wildcard $(MLX_PATH)/*),)
		@git submodule update --init --recursive
		@echo "$(GREEN)Downloaded mlx submodule.$(COLOR_RESET)"
    endif

    # Check if libft is compiled
    ifeq ($(wildcard $(LIBFT_PATH)/libft.a),)
		@make -s -C $(LIBFT_PATH)
    endif
	@echo "$(GREEN)Libft compiled ✅$(COLOR_RESET)"

    # Check if mlx is compiled
    ifeq ($(wildcard $(MLX_PATH)/libmlx.a),)
		@make -s -C $(MLX_PATH)
    endif
	@echo "$(GREEN)Mlx compiled ✅$(COLOR_RESET)"

$(NAME): $(OBJDIR) $(OBJ) $(EXCLUDED_SRC_OBJ)
	@$(CC) $(OBJ) $(EXCLUDED_SRC_OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(BOLD_GREEN)Program Compiled 🔥$(COLOR_RESET)"

$(TEST_EXECUTABLE): $(OBJDIR) $(OBJ) $(EXCLUDED_TEST_OBJ)
	@$(CC) $(OBJ) $(EXCLUDED_TEST_OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(TEST_EXECUTABLE)
	@echo "$(BOLD_GREEN)Tester Compiled 🤖$(COLOR_RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

macos: $(OBJS)
	@if [ ! -f $(LIBFTPATH)/libft.a ]; then \
 		echo "Building libft..."; \
		make -C $(LIBFTPATH); \
	else \
		echo "libft.a already exists"; \
	fi
	if [ ! -d "./lib/mlx" ]; then \
		git submodule add https://github.com/42Paris/minilibx-linux.git lib/mlx; \
	fi
	make -C $(MLX_LIB)
	$(CC) $(OBJS) -g -L /usr/X11/lib -lX11 -lmlx -lXext -Llib/libft -lft -o $(NAME)

clean:
	@rm -rf $(OBJDIR) $(EXECUTABLE) $(TEST_EXECUTABLE)
	@cd $(LIBFT_PATH) && make -s clean
	@echo "$(RED) Objects removed$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX_PATH)/*.a
	@cd $(LIBFT_PATH) && make -s fclean
	@echo "$(RED) Full clean$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re libft test dependencies
