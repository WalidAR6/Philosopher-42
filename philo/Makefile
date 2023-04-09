NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread

SRC = src/philo.c\
		src/parser.c\
		src/fill_info.c\
		src/ft_atoi.c\
		src/philo_creation.c\
		src/create_func.c\
		src/actions.c\
		src/utils.c

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