/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:03:21 by buozcan           #+#    #+#             */
/*   Updated: 2023/12/04 02:42:38 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(t_data *data)
{
	data->mtx_loc = transform_mtx(vec3_set(0, 0, 0), vec3_set(0, 0, 0), vec3_set(0.5, -0.5, -0.5));
	data->mtx_glob = transform_mtx(vec3_set(-5, 5, 0), vec3_set(0, 0, data->time), vec3_set(1, 1, 1));
	draw_image(data);
	data->time++;
	return (data->time);
}