INCLUDES = -I/usr/include -Imlx -I./

INCLUDES_MAC = -I .

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

MLX_FLAGS_MAC = -L . -lmlx -lft -lftprintf -framework OpenGL -framework AppKit

SRCS = main.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $?

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

all: $(NAME)

fclean: clean
	rm -rf $(NAME).out

clean:
	rm -rf *.o

re: fclean all
