/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:03:21 by buozcan           #+#    #+#             */
/*   Updated: 2023/12/07 17:16:37 by bgrhnzcn         ###   ########.fr       */
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
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	data->time++;
	return (data->time);
}
