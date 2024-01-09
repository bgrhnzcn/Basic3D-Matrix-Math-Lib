/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:03:21 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/09 19:05:15 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(t_data *data)
{
	while (data->time % 2)
	{
		data->mtx_loc = transform_mtx(vec3_set(0, 0, 0),
				vec3_set(45, 35.16, 0), vec3_set(1, -1, -10));
		data->mtx_glob = transform_mtx(data->translation,
				data->rotation, data->scale);
		draw_image(data);
		mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
	}
	data->time++;
	return (data->time);
}
