INCLUDES = -I/usr/include -Imlx

INCLUDES_MAC = -Imlx

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

MLX_FLAGS_MAC = -L . -lmlx -framework OpenGL -framework AppKit

SRCS = main.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(INCLUDES_MAC) $?

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS_MAC)

all: $(NAME)

fclean: clean
	rm -rf $(NAME).out

clean:
	rm -rf *.o

re: fclean all
