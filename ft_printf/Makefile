# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvalogne <gvalogne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 10:41:29 by gvalogne          #+#    #+#              #
#    Updated: 2023/12/06 11:52:54 by gvalogne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		ft_printf.c ft_print_unsigned.c ft_printf_utils.c \
			ft_itoa.c ft_put.c\

OBJS            = $(SRC:.c=.o)

CC                = cc
RM                = rm -f
CFLAGS            = -Wall -Wextra -Werror -I.

NAME            = libftprintf.a

all:            $(NAME)

$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:        	$(BONUS_OBJS) $(OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
				$(RM) $(OBJS)

fclean:            clean
				$(RM) $(NAME)

re:                fclean $(NAME)

.PHONY:            all clean fclean re bonus