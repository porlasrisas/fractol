# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Werror -Wextra

# Directorios de tu proyecto
INCLUDES    = -I includes -I libft -I ft_printf
SRCDIR      = src
LIBFTDIR    = libft
FTPRINTFDIR = ft_printf

# Ficheros fuente principales de fractol
SRC_FILES   = main.c  events.c\
              draw.c  fractal_utils.c \
              parser.c fractal_utils_2.c \
              # ... (y los que necesites)

# Rutas completas a los .c
SRCS        = $(addprefix $(SRCDIR)/, $(SRC_FILES))
# Ficheros objeto
OBJS        = $(SRCS:.c=.o)

# Librerías propias
LIBFT       = -L $(LIBFTDIR) -lft
FT_PRINTF   = -L $(FTPRINTFDIR) -lftprintf

# **************************************************************************** #
#                        SELECCIÓN DE OS (mac / linux)                         #
# **************************************************************************** #
# Por defecto, si no especificas nada, digamos que compile para mac. 
# Si haces "make linux", se cambia la variable OS=linux.

OS ?= mac

# Definimos variables que cambiarán según OS

ifeq ($(OS), mac)
    MLX_DIR    = minilibx_opengl
    MLX_FLAGS  = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
    MLX_INC    = -I $(MLX_DIR)
else ifeq ($(OS), linux)
    MLX_DIR    = minilibx-linux
    MLX_FLAGS  = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
    MLX_INC    = -I $(MLX_DIR)
endif

# Agregamos MLX_INC a la variable de includes
INCLUDES   += $(MLX_INC)

# **************************************************************************** #
#                                   REGLAS                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	# 1) Compilamos la MLX que corresponda
	@$(MAKE) -C $(MLX_DIR)
	# 2) Compilamos libft y ft_printf
	@$(MAKE) -C $(LIBFTDIR)
	@$(MAKE) -C $(FTPRINTFDIR)
	# 3) Linkamos todo
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "Compilado con éxito $(NAME) para $(OS)!"

# Regla genérica para compilar cada .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(FTPRINTFDIR)
	@rm -f $(OBJS)
	@echo "Clean de objetos fractol"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(FTPRINTFDIR)
	@rm -f $(NAME)
	@echo "Fclean fractol"

re: fclean all

# Reglas personalizadas para "make mac" y "make linux"

mac:
	@$(MAKE) OS=mac all

linux:
	@$(MAKE) OS=linux all

.PHONY: all clean fclean re mac linux
