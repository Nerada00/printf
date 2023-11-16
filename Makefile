SRCS =	ft_printf.c\
		ft_printf_fonction.c\

OBJS = ${SRCS:.c=.o}


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus: ${OBJS} ${OBJSBONUS}
			ar -rcs ${NAME} ${OBJS} ${OBJSBONUS}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
			${RM} ${NAME}

re: fclean all


.PHONY:  all clean fclean re
