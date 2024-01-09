/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 19:49:59 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(t_data *dt, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < dt->win.width)
	{
		j = 0;
		while (j < dt->win.height)
		{
			put_pixel(&dt->img, i, j, color);
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

	fill_img(data, set_color(0, 0, 0, 0));
	trans_map = renderer(data, 0, 0, 0);
	if (trans_map == NULL)
		exit(1);
	draw_map(data, trans_map);
	free(trans_map);
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
	data->time++;
	return (0);
}
