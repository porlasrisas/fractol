# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 15:57:01 by guigonza          #+#    #+#              #
#    Updated: 2025/04/07 16:53:08 by guigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Werror -Wextra

INCLUDES    = -I includes -I libft -I ft_printf
SRCDIR      = src
LIBFTDIR    = libft
FTPRINTFDIR = ft_printf

SRC_FILES   = main.c events.c draw.c fractal_utils.c \
              parser.c fractal_utils_2.c

SRCS        = $(addprefix $(SRCDIR)/, $(SRC_FILES))

OBJS        = $(SRCS:.c=.o)

LIBFT       = -L $(LIBFTDIR) -lft
FT_PRINTF   = -L $(FTPRINTFDIR) -lftprintf

MLX_DIR     = minilibx-linux
MLX_FLAGS   = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC     = -I $(MLX_DIR)

INCLUDES   += $(MLX_INC)

# **************************************************************************** #
#                                  REGLAS                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	# Compilamos la librería MLX
	@$(MAKE) -C $(MLX_DIR)
	# Compilamos libft y ft_printf
	@$(MAKE) -C $(LIBFTDIR)
	@$(MAKE) -C $(FTPRINTFDIR)
	# Linkamos todos los objetos y librerías
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "Compilado con éxito $(NAME)!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(FTPRINTFDIR)
	@rm -f $(OBJS)
	@echo "Objetos de fractol limpiados"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(FTPRINTFDIR)
	@rm -f $(NAME)
	@echo "Proyecto fractol completamente limpio"

re: fclean all

.PHONY: all clean fclean re
