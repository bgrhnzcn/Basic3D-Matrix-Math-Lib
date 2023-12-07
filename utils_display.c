/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/07 15:46:04 by bgrhnzcn         ###   ########.fr       */
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

void	fill_img(t_img *img, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

t_vec3	*renderer(t_data *d, int i, int j, int curr)
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
			trans_map[curr] = graphic_pipeline(d->proj_mtx,
					d->mtx_glob, d->mtx_loc, d->map->verteces[curr]);
			j++;
		}
		i++;
	}
	return (trans_map);
}

int	draw_image(t_data *data)
{
	t_vec3		*trans_map;

	fill_img(&data->img, set_color(0, 0, 0, 0));
	trans_map = renderer(data, 0, 0, 0);
	if (trans_map == NULL)
		exit(1);
	draw_map(data, trans_map);
	free(trans_map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	data->time++;
	return (0);
}
