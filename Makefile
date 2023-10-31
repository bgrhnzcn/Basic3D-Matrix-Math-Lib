INCLUDES = -I/usr/include -Imlx

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRCS = main.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $(INCLUDES) $?

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

all: $(NAME)

fclean: clean
	rm -rf $(NAME).out

clean:
	rm -rf *.o

re: fclean all
