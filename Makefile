NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -MP

SRCS = ./ft_printf.c \
./ft_printf_utils.c \
./ft_put.c

all: ${NAME}

OBJ = ${SRCS:.c=.o}
OBJ_D = ${OBJ:.o=.d}

%.o:	%.c
	${CC} ${CFLAGS} -o $@ -c $<

-include ${OBJ_D}

${NAME}: ${OBJ}
	ar -rc ${NAME} ${OBJ}
clean:
	rm -f ${OBJ} ${OBJ_D}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all
