/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 06:15:51 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_tri(t_data *data, t_tri *tris, int j, t_color color)
{
	draw_line(&(data)->img, tris[j].pts[0],
		tris[j].pts[1], color);
	draw_line(&(data)->img, tris[j].pts[1],
		tris[j].pts[2], color);
	draw_line(&(data)->img, tris[j].pts[2],
		tris[j].pts[0], color);
}

void	fill_img(t_data *data, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			put_pixel(&(data->img), i, j, color);
			j++;
		}
		i++;
	}
}

t_vec3	*render_pipeline(t_data *d, int i, int j, int curr)
{
	t_vec3	*trans_map;

	trans_map = malloc(d->map->map_x * d->map->map_y * sizeof(t_vec3));
	if (trans_map == NULL)
		return (NULL);
	while (i < d->map->map_y)
	{
		j = 0;
		while (j < d->map->map_x)
		{
			curr = (i * d->map->map_x) + j;
			trans_map[curr] = transform_pipeline(d->orto_mtx,
					d->mtx_glob, d->mtx_loc, d->map->verteces[curr]);
			j++;
		}
		i++;
	}
	return (trans_map);
}

void	draw_map_ver(t_data *d, t_vec3 *tr_map, t_color *ver_col)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	while (j < d->map->map_x)
	{
		i = 0;
		while (i < d->map->map_y -1)
		{
			k = (i * d->map->map_x) + j;
			gradient_line(&d->img, tr_map[k], tr_map[k + d->map->map_x],
				set_gradient(ver_col[k], ver_col[k + d->map->map_x]));
			i++;
		}
		j++;
	}
}

void	draw_map_hor(t_data *d, t_vec3 *tr_map, t_color *ver_col)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < d->map->map_y)
	{
		j = 0;
		while (j < d->map->map_x -1)
		{
			k = (i * d->map->map_x) + j;
			gradient_line(&d->img, tr_map[k], tr_map[k + 1],
				set_gradient(ver_col[k], ver_col[k + 1]));
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *d, t_vec3 *tr_map)
{
	t_color		*ver_col;

	ver_col = d->map->vertex_colors;
	draw_map_ver(d, tr_map, ver_col);
	draw_map_hor(d, tr_map, ver_col);
}

int	draw_image(t_data *data)
{
	t_vec3		*trans_map;

	fill_img(data, set_color(0, 0, 0, 0));
	trans_map = render_pipeline(data, 0, 0, 0);
	if (trans_map == NULL)
		exit(1);
	draw_map(data, trans_map);
	free(trans_map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	data->time++;
	return (0);
}
