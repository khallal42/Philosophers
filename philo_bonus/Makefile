NAME = philo_bonus
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -rf

CFILES = philo_bonus.c \
		 ft_atoi.c \
		 get_time.c \
		 philo_utils1_bonus.c \

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