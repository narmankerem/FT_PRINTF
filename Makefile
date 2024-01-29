# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knarman <knarman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 04:57:26 by knarman           #+#    #+#              #
#    Updated: 2023/12/26 05:38:07 by knarman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror
SRC = 	./ft_printf.c		\
		./ft_printf_utilities.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	${CC} $(FLAG) -c $(SRC)
	ar rc $(NAME) ${OBJ}
clean:
	${RM}  ${OBJ}
fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re