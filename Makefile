# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knarman <knarman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 04:57:26 by knarman           #+#    #+#              #
#    Updated: 2023/12/26 04:57:28 by knarman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
LIBC = ar rcs
SRCS = ft_printf.c ft_printf_utilities.c   \
       
OBJS = ${SRCS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

c: clean
clean:
	${RM} ${OBJS}

f: fclean
fclean: clean
	${RM} ${NAME}

r:re
re: fclean all

.PHONY : all clean fclean re