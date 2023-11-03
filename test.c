/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:12 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/03 21:53:46 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
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

typedef struct s_cir{
	t_img	*img;
	t_pos	*pos;
	t_mng	*mng;
}	t_cir;

int	get_pos(t_pos *mouse)
{
	if (mlx_mouse_get_pos(mouse->mng->win, &mouse->x, &mouse->y))
		return (1);
	printf("sin(45): %f\n", sin(deg_to_rad(45)));
	printf("posx: %d, posy: %d\n", mouse->x, mouse->y);
	return (0);
}

t_img	*image_cons(void *mlx, int dim_x, int dim_y)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx, dim_x, dim_y);
	img->img_data = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->size_len, &img->endian);
	if (img->img_data == NULL)
	{
		free(img);
		return (NULL);
	}
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

int	change_color(int keycode, t_cir *cir)
{
	if (keycode == 0x0)
	{
		draw_circle(cir->img, cir->pos, 156, 0x0FFFFF00);
		if (mlx_put_image_to_window(cir->mng->mlx, cir->mng->win, cir->img->img_ptr, 0, 0))
			return (0);
	}
	else if (keycode == 0x1)
	{
		draw_circle(cir->img, cir->pos, 156, 0x0F0000FF);
		if (mlx_put_image_to_window(cir->mng->mlx, cir->mng->win, cir->img->img_ptr, 0, 0))
			return (0);
	}
	else if (keycode == 0x35)
	{
		mlx_destroy_window(cir->mng->mlx, cir->mng->win);
		exit(0);
	}
	return (0);
}

int	deneme(t_cir *cir)
{
	int	i;
	int	j;

	if (mlx_mouse_get_pos(cir->mng->win, &cir->pos->x, &cir->pos->y))
		return (0);
	i = -2;
	j = -2;
	while (i < 3)
	{
		while (j < 3)
		{
			put_pixel(cir->img, cir->pos->x + j, cir->pos->y + i, 0xFF00FFFF);
			printf("posx: %d, posy: %d\n", cir->pos->x, cir->pos->y);
			j++;
		}
		j = -2;
		i++;
	}
	mlx_put_image_to_window(cir->mng->mlx, cir->mng->win, cir->img->img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_mng	mng;
	t_img	*img;
	t_pos	mouse;
	t_cir	cir;
	int		width;
	int		height;

	printf("deneme");
	mng.mlx = mlx_init();
	//if (mng.mlx == NULL)
	width = 800;
	height = 600;
	mng.win = mlx_new_window(mng.mlx, width, height, "Test");
	//if (mng.win == NULL)
	img = image_cons(mng.mlx, width, height);
	//if (img == NULL)
	draw_cube(img, 0x00000000);
	cir.img = img;
	cir.mng = &mng;
	t_pos pos;
	cir.pos = &pos;
	cir.pos->x = width / 2;
	cir.pos->y = height / 2;
	//draw_circle(img, cir.pos, 256, 0x00FF0000);
	//draw_circle(img, cir.pos, 156, 0x0FFFFFFF);
	mouse.mng = &mng;
	mouse.x = 0;
	mouse.y = 0;
	mlx_put_image_to_window(mng.mlx, mng.win, img->img_ptr, 0, 0);
	cir.pos = &mouse;
	mlx_mouse_hide();
	mlx_hook(mng.win, 2, 0, change_color, &cir);
	mlx_loop_hook(mng.mlx, deneme, &cir);
	mlx_loop(mng.mlx);
	system("leaks fdf");
	return (0);
}
