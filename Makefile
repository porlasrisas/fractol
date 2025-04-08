# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 15:57:01 by guigonza          #+#    #+#              #
#    Updated: 2025/04/08 15:47:05 by guigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
PRINTF_DIR  = ft_printf
MLX_DIR     = minilibx-linux

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/events.c \
      $(SRC_DIR)/draw.c \
      $(SRC_DIR)/fractal_utils.c \
      $(SRC_DIR)/fractal_utils_2.c \
      $(SRC_DIR)/parser.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -Iincludes -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

GREEN = \033[0;32m
YELLOW = \033[1;33m
RESET = \033[0m
RED = '\033[0;31m'

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	@make -s -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)Compilación completada: $(NAME)$(RESET)"
	@echo "$(GREEN)---------------------------------------------------------------------------------------------------"
	@echo "$(YELLOW) ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░░▒▓██████▓▒░"
	@echo "$(YELLOW)░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░"
	@echo "$(YELLOW)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░    ░▒▓██▓▒░░▒▓█▓▒░░▒▓█▓▒░"
	@echo "$(YELLOW)░▒▓█▓▒▒▓███▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░  ░▒▓██▓▒░  ░▒▓████████▓▒░"
	@echo "$(YELLOW)░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓▓█▓▒░░▒▓██▓▒░    ░▒▓█▓▒░░▒▓█▓▒░"
	@echo "$(YELLOW)░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░"
	@echo "$(YELLOW) ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░"
	@echo "$(GREEN)---------------------------------------------------------------------------------------------------"
	@echo "$(GREEN)\n ¡Enhorabuena champion, todo compilado!\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Objetos de fractol y submódulos limpiados$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@echo "$(RED)Proyecto fractol completamente limpio$(RESET)"


re: fclean all

.PHONY: all clean fclean re
