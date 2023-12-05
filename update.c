/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:03:21 by buozcan           #+#    #+#             */
/*   Updated: 2023/12/05 19:10:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(t_data *data)
{
	data->mtx_loc = transform_mtx(vec3_set(0, 0, 0), vec3_set(45+ data->time / 20, 35.16 + data->time / 20, 0), vec3_set(1, -1, -1));
	data->mtx_glob = transform_mtx(vec3_set(0, 0, 0), vec3_set(0, 0, 0), vec3_set(1, 1, 1));
	draw_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	data->time++;
	return (data->time);
}