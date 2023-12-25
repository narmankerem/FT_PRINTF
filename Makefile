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