# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czinsou <czinsou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/16 00:02:06 by czinsou            #+#    #+#              #
#    Updated: 2026/05/16 00:02:06 by czinsou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		= cub3d

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror \
			  -Iinclude \
			  -Iinclude/minilibx-linux

MLX_FLAGS	= -Linclude/minilibx-linux \
			  -lmlx -lXext -lX11 -lm

SRC_PARSING	= src/parsing/parsing.c \
			  src/parsing/checkrgb.c \
			  src/parsing/checkmap.c \
			  src/parsing/getmap.c \
			  src/parsing/utils.c

SRC_EXEC	= src/exec/init.c \
			  src/exec/hook.c \
			  src/exec/texture.c \
			  src/exec/raycasting.c \
			  src/exec/render.c \
			  src/exec/mouvement.c

SRC_MAIN	= src/main.c

LIBFT_SRC	= $(wildcard include/libft/*.c)
GNL_SRC		= $(wildcard include/gnl/*.c)

SRC			= $(SRC_PARSING) $(SRC_EXEC) $(SRC_MAIN) \
			  $(LIBFT_SRC) $(GNL_SRC)

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

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