NAME = philo
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -rf

CFILES = get_time.c \
		 philo.c \
		 ft_atoi.c \
		 philo_utils1.c \
		 philo_utils2.c

OBJ = ${CFILES:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all bonus clean fclean re