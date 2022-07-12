# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:48:15 by ankasamanya       #+#    #+#              #
#    Updated: 2022/07/12 23:28:22 by ankasamanya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	fract-ol.c input.c the_math.c \
		colour.c hooks.c mandelbrot.c \
		zoom.c move_it.c julia.c burningship.c

OBJ =	$(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
MV = mv

LIBFT =	./Libft/libft.a

MLX =	libmlx.a -framework OpenGL -framework AppKit -o

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@$(MAKE) -C mlx
	@$(MV) mlx/libmlx.a mlx/..
	@$(MAKE) bonus -C Libft
	@$(CC) $(FLAGS) $(OBJ) $(MLX) $(NAME) $(LIBFT)

clean:
	@$(MAKE) fclean -C Libft
	@$(RM) $(OBJ) $(BONUS_OBJ) libmlx.a

fclean: clean
	@($(RM) $(NAME))

re: fclean all

.PHONY: all clean fclean re