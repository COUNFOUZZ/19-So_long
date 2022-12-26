# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabda <aabda@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 20:58:10 by aabda             #+#    #+#              #
#    Updated: 2022/12/26 18:33:20 by aabda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
DIR		= srcs/
GNL		= gnl/
MLX		= ./mlx/libmlx.a
CC		= gcc
FLAGS	= -Wall 
MFLAGS	= -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS = $(GNL)get_next_line.c $(GNL)get_next_line_utils.c \
	$(DIR)main.c $(DIR)utils.c \
	$(DIR)parsing.c $(DIR)libft_utils.c \
	$(DIR)map_utils.c $(DIR)mlx_utils.c \
	$(DIR)movement.c $(DIR)check_coin.c

OBJS = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	make -sC ./mlx

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MFLAGS) -o $(NAME) $(OBJS)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean -C ./mlx

re: fclean all

.PHONY:	all clean fclean re norm