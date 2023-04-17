NAME = philo_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread

SRC = src/philo_bonus.c\
		src/parser_bonus.c\
		src/utils_bonus.c\
		src/utils_bonus_2.c\
		src/actions_bonus.c\
		src/routine_bonus.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c inc/philo_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean