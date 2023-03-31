NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread

SRC = src/philo.c\
		utils/ft_atoi.c\
		utils/is_digite.c\
		src/parser.c\
		src/create_philo.c\
		src/routine.c\
		src/action.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c inc/philo.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean