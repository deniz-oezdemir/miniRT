# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 22:25:40 by denizozd          #+#    #+#              #
#    Updated: 2024/05/07 23:06:30 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main executable
NAME = minirt
# Test executable
TEST_EXECUTABLE = test_minirt

# Compilation options
CC = cc
CFLAGS = ##-Wall -Wextra -Werror

# Libft library
LIBFT_PATH = lib/libft
LIBFT_FLAGS = -Llib/libft -lft

# MLX library
MLX_PATH = lib/mlx
MLX_FLAGS = -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

# Source files directory
SRCDIR = src
# Test files directory
TESTDIR = tests
# Object files directory
OBJDIR = obj

INCLUDE = -I/usr/include -Ilib/mlx

# Source files (excluding main.c and test files)
SRC = $(wildcard $(SRCDIR)/**/*.c)
SRC := $(filter-out $(SRCDIR)/main.c, $(SRC))
SRC := $(filter-out $(wildcard $(TESTDIR)/*.c), $(SRC))

# Excluded source files
EXCLUDED_SRC = $(wildcard $(SRCDIR)/*.c)
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

all: $(NAME)

test: $(TEST_EXECUTABLE)

# Check if mlx has been downloaded
ifeq ($(wildcard $(MLX_PATH)/*),)
	git submodule update --init --recursive
endif

# Check if libft is compiled
ifndef $(wildcard $(LIBFT_PATH)/libft.a)
	make -C $(LIBFT_PATH)
endif
#echo "$(GREEN)libft COMPILED.$(COLOR_RESET)"
#$(shell echo "$(GREEN)libft COMPILED.$(COLOR_RESET)")

# Check if mlx is compiled
ifndef $(wildcard $(MLX_PATH)/libmlx.a)
	make -C $(MLX_PATH)
endif
#@echo "$(GREEN)mlx COMPILED.$(COLOR_RESET)"

$(NAME): $(OBJDIR) $(OBJ) $(EXCLUDED_SRC_OBJ)
    # Check if mlx has been downloaded
    ifeq ($(wildcard $(MLX_PATH)/*),)
		git submodule update --init --recursive
    endif
    ifdef $(wildcard $(MLX_PATH)/libmlx.a)
		$(info Mlx library already compiled)
    endif
	@$(CC) $(OBJ) $(EXCLUDED_SRC_OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(TEST_EXECUTABLE): $(OBJDIR) $(OBJ) $(EXCLUDED_TEST_OBJ)
	$(CC) $(OBJ) $(EXCLUDED_TEST_OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(TEST_EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE) $(TEST_EXECUTABLE)
	cd $(LIBFT_PATH) && make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_PATH)/*.a
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re libft test
