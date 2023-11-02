/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:12 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/02 18:39:51 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/keysym.h>

typedef struct s_mng{
	void	*mlx;
	void	*win;
}	t_mng;

typedef struct s_pos{
	t_mng	*mng;
	int		x;
	int		y;
}	t_pos;

typedef struct s_img{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_len;
	int		endian;
	char	*img_data;
}	t_img;

int	get_pos(t_pos *mouse)
{
	mlx_mouse_get_pos(mouse->mng->mlx, mouse->mng->win, &mouse->x, &mouse->y);
	printf("posx: %d, posy: %d\n", mouse->x, mouse->y);
}

t_img	*image_cons(void *mlx, int dim_x, int dim_y)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->endian = 0;
	img->bits_per_pixel = 32;
	img->size_len = ((img->bits_per_pixel / 8) * dim_x);
	img->img_ptr = mlx_new_image(mlx, dim_x, dim_y);
	img->img_data = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->size_len, &img->endian);
	return (img);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*point;

	point = (img->img_data) + ((img->bits_per_pixel / 8) * x) + (img->size_len * y);
	if (img->endian == 1)
	{
		point[0] = (color >> 24);
		point[1] = (color >> 16) & 0xFF;
		point[2] = (color >> 8) & 0xFF;
		point[3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		point[0] = (color) & 0xFF;
        point[1] = (color >> 8) & 0xFF;
        point[2] = (color >> 16) & 0xFF;
        point[3] = (color >> 24);
	}
}

void	draw_cube(t_img *img, int color)
{
	int	dim_x;
	int	dim_y;
	int	i;
	int	j;

	dim_x = 200;
	dim_y = 200;
	i = 0;
	j = 0;
	while (j < dim_y)
	{
		while (i < dim_x)
		{
			put_pixel(img, i, j, color);
			i++;
		}
		i = 0;
		j++;
	}
}

int	main(void)
{
	t_mng	mng;
	t_img	*img;
	t_pos	mouse;
	int		width;
	int		height;

	printf("deneme");
	mng.mlx = mlx_init();
	width = 800;
	height = 600;
	mng.win = mlx_new_window(mng.mlx, width, height, "Test");
	img = image_cons(mng.mlx, width, height);
	draw_cube(img, 0xFFFFFF);
	mouse.mng = &mng;
	mouse.x = 0;
	mouse.y = 0;
	mlx_put_image_to_window(mng.mlx, mng.win, img->img_ptr, 200, 200);
	mlx_loop_hook(mng.mlx, get_pos, &mouse);
	mlx_loop(mng.mlx);
}
