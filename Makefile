# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 11:37:46 by ziratya           #+#    #+#              #
#    Updated: 2024/08/19 19:48:10 by ziratya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	gcc
FLAGS 	=   -g
MLX_PATH = minilibx-linux/libmlx.a
MLX_FILE = libmlx.a
MLX_FLAGS = -L/usr/X11R6/lib -lX11 -lXext

SRC 	=	$(wildcard src/*.c)
OBJ 	=	$(patsubst %.c,%.o,$(SRC))
RM 		=	rm -f

.SUFFIXES: .c .o

$(NAME): $(OBJ)
	make -C minilibx-linux/
	$(CC) $(FLAGS) $(OBJ) $(MLX_PATH) $(MLX_FLAGS) $(LIBFT_FILE) -o $(NAME) -I includes/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I includes/

all: $(NAME)

do_configure:
	echo "Configuring minilibx..."
	make -C minilibx-linux/ do_configure
	echo "Minilibx configuration complete."

clean:
	echo "Deleting Obj files in $(MLX_PATH)...\n"
	make clean -sC minilibx-linux/
	echo "Deleting Obj files in $(LIBFT_PATH)...\n"
	make clean -sC $(LIBFT_PATH)
	echo "Done\n"
	echo "Deleting fractol object files...\n"
	rm -f $(OBJ)
	echo "Done\n"

fclean: clean
	echo "Deleting fractol executable..."
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	echo "Done\n"

re: fclean all

.PHONY: all do_configure clean fclean re