/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:12 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/03 17:34:37 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
//#include <X11/keysym.h>

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
	mlx_mouse_get_pos(mouse->mng->win, &mouse->x, &mouse->y);
	printf("sin(45): %f\n", sin(deg_to_rad(45)));
	//printf("posx: %d, posy: %d\n", mouse->x, mouse->y);
	return (0);
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

void	put_pixel(t_img *img, int x, int y, unsigned int color)
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

void	draw_cube(t_img *img, unsigned int color)
{
	int	dim_x;
	int	dim_y;
	int	i;
	int	j;

	dim_x = 400;
	dim_y = 300;
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

void	draw_circle(t_img *img, t_pos *offset, double rad, unsigned int color)
{
	double	ang;

	ang = 0;
	while (rad >= 0)
	{
		while (ang <= 360)
		{
			put_pixel(img, offset->x + rad * sin(deg_to_rad(ang)), offset->y + rad * cos(deg_to_rad(ang)), color);
			ang += 0.01;
		}
		ang = 0;
		rad--;
	}
}

int	close(t_mng *mng)
{
	mlx_destroy_window(mng->mlx, mng->win);
	exit(0);
	return (1);
}

int	main(void)
{
	t_mng	mng;
	t_img	*img;
	t_pos	mouse;
	t_pos	cir;
	int		width;
	int		height;

	printf("deneme");
	mng.mlx = mlx_init();
	if (mng.mlx == NULL)
		exit(0);
	width = 800;
	height = 600;
	cir.x = width / 2;
	cir.y = height / 2;
	mng.win = mlx_new_window(mng.mlx, width, height, "Test");
	if (mng.win == NULL)
		exit(0);
	img = image_cons(mng.mlx, width, height);
	//draw_cube(img, 0x00FF00FF);
	draw_circle(img, &cir, 256, 0x00FF0000);
	draw_circle(img, &cir, 156, 0x0FFFFFFF);
	mouse.mng = &mng;
	mouse.x = 0;
	mouse.y = 0;
	mlx_put_image_to_window(mng.mlx, mng.win, img->img_ptr, 0, 0);
	mlx_loop_hook(mng.mlx, get_pos, &mouse);
	mlx_hook(mng.win, 17, 0, close, &mng);
	mlx_loop(mng.mlx);
}
