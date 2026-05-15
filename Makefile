NAME		= cub3d

CC			= gcc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux
MLX_FLAGS   = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC_PARSING	= src/parsing/parsing.c \
			  src/parsing/parse_textures.c \
			  src/parsing/parse_colors.c \
			  src/parsing/parse_map.c \
			  src/parsing/validate_map.c \
			  src/parsing/parsing_utils.c

 SRC_EXEC    = src/exec/init.c \
                src/exec/hooks.c \
                src/exec/textures.c \
                src/exec/raycasting.c \
                src/exec/dda.c \
                src/exec/render.c \
                src/exec/movement.c

SRC_MAIN	= src/main.c

LIBFT_SRC	= $(wildcard include/libft/*.c)
GNL_SRC		= $(wildcard include/gnl/*.c)

SRC			= $(SRC_PARSING) $(SRC_MAIN) $(SRC_EXEC) $(LIBFT_SRC) $(GNL_SRC)
OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(MLX_FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "=== Test valid map ==="
	./$(NAME) map/subject.cub
	@echo ""
	@echo "=== Test bad extension ==="
	-./$(NAME) map/subject.cb
	@echo ""
	@echo "=== Test nonexistent file ==="
	-./$(NAME) map/nonexist.cub

.PHONY: all clean fclean re test
