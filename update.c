/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:03:21 by buozcan           #+#    #+#             */
/*   Updated: 2023/12/02 22:11:55 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(t_data *data)
{
	data->mtx_loc = transform_mtx(vec3_set(0, 0, 0), vec3_set(45, 35.16, 180), vec3_set(3, -3, -10));
	data->mtx_glob = transform_mtx(vec3_set(0, 0, 0), vec3_set(0, data->time, 0), vec3_set(1, 1, 1));
	draw_image(data);
	data->time++;
	return (data->time);
}