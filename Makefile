INCLUDES_LINUX = -I/usr/include -Imlx -I .

INCLUDES_MAC = -I .

NAME = fdf

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

MLX_FLAGS_LINUX = linux_lib/libftprintf.a linux_lib/get_next_line.a linux_lib/libft.a libmlx.a\
			-Bdynamic -L/usr/lib/X11 -lXext -lX11 -lm

MLX_FLAGS_MAC = mac_lib/libft.a mac_lib/get_next_line.a mac_lib/libftprintf.a mac_lib/libmlx.a -Bdynamic -framework OpenGL -framework AppKit

SRCS = main.c input.c mtx3_basic.c mtx4_basic.c inits.c transforms.c \
	utils_bresenham_line.c utils_display.c map.c utils.c vec_conv.c \
	vec2_double.c vec2_op.c vec2_vec2.c vec3_double.c vec3_op.c vec3_vec3.c\
	vec4_double.c vec4_op.c vec4_vec4.c mesh_init.c mesh_init_utils.c fdf_map.c \
	colors.c gradient_line.c arrays.c pipeline.c update.c errors.c \
	draw_map.c

ifeq ($(shell uname),Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
	INCLUDES = $(INCLUDES_LINUX)
else
	MLX_FLAGS = $(MLX_FLAGS_MAC)
	INCLUDES = $(INCLUDES_MAC)
endif

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $?

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

all: $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

re: fclean all
