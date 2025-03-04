# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 11:43:13 by labdelkh          #+#    #+#              #
#    Updated: 2025/02/14 11:43:15 by labdelkh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_validate_args.c ft_errors.c ft_read_map.c ft_set_game_def.c \
		ft_validate_map.c ft_utils.c ft_check_solvable.c ft_init_game.c \
		ft_handle_keys.c so_long.c

OBJS = ${SRCS:.c=.o}

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -I/usr/include -Imlx -c $< -o $@

${NAME}: ${MAIN_OBJ} ${OBJS} libft/libft.a
		${CC} ${CFLAGS} ${MAIN_OBJ} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -Llibft -lft -o ${NAME}

all: libft/libft.a $(NAME)

libft/libft.a:
		make -C libft

clean:
		${RM} ${MAIN_OBJ} ${OBJS}
		make -C libft fclean

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft/libft.a
