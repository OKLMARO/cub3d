# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 15:42:38 by oamairi           #+#    #+#              #
#    Updated: 2026/05/25 15:52:52 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/parsing/checkmap.c src/parsing/checkrgb.c src/parsing/getmap.c \
			src/parsing/parsing.c src/parsing/utils.c src/main.c \
			include/gnl/get_next_line.c include/gnl/get_next_line_utils.c \
			src/exec/hook.c src/exec/init.c src/exec/mouvement.c \
			src/exec/raycasting.c src/exec/render.c src/exec/texture.c\

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

LIBFT	=	include/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C include/libft bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	$(MAKE) -C include/libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C include/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re