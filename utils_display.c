/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/29 02:30:51 by bgrhnzcn         ###   ########.fr       */
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

t_vec3	*get_screen_points(t_data *d, int i, int j, int curr)
{
	t_vec3	*trans_map;
	t_mtx4	mtx;

	trans_map = malloc(d->map->map_x * d->map->map_y * sizeof(t_vec3));
	if (trans_map == NULL)
		return (NULL);
	while (i < d->map->map_y)
	{
		j = 0;
		while (j < d->map->map_x)
		{
			curr = (i * d->map->map_x) + j;
			mtx = loc_to_glob(VEC3_NULL, vec3_set(45, 35.264, -90), VEC3_ONE);
			trans_map[curr] = glob_to_clip(d, mtx, curr);
			trans_map[curr] = clip_to_screen(trans_map[curr]);
			j++;
		}
		i++;
	}
	return (trans_map);
}

void	draw_map(t_data *d, t_vec3 *tr_map)
{
	int			i;
	int			j;
	int			k;
	t_gradient	grad;
	t_color		*ver_col;

	ver_col = d->map->vertex_colors;
	while (i < d->map->map_y - 1)
	{
		j = 0;
		while (j < d->map->map_x - 1)
		{
			k = (i * d->map->map_x) + j;
			grad = set_gradient(ver_col[k], ver_col[k + 1]);
			gradient_line(&d->img, tr_map[k], tr_map[k + 1], grad);
			grad = set_gradient(ver_col[k], ver_col[k + d->map->map_x]);
			gradient_line(&d->img, tr_map[k], tr_map[k + d->map->map_x], grad);
			j++;
		}
		i++;
	}
}

int	draw_image(t_data *data)
{
	t_vec3		*trans_map;

	fill_img(data, set_color(0, 0, 0, 0));
	trans_map = get_screen_points(data, 0, 0, 0);
	if (trans_map == NULL)
		exit(1);
	draw_map(data, trans_map);
	free(trans_map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
