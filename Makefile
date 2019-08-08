# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 18:45:27 by marrodri          #+#    #+#              #
#    Updated: 2019/07/31 18:45:29 by marrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# basic makefile, fully complete later in the future
NAME = fractol

CFLAGS = -Wall -Wextra -Werror -g
I_FT = -I libft/
INC = -I ./includes/minilibx_macos
MLX = -L ./includes/minilibx_macos -lmlx -framework OpenGl -framework AppKit

SRC = fract_main.c fract_init.c fract_ft.c \
		 fract_mandelbrot.c #fract_julia.c \
		fract_tricorn.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(INC) $(I_FT) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

# cc  -I ./includes/minilibx_macos fract_main.c  -L ./includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit -L ./includes/libft -lft
