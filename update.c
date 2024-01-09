/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:03:21 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/09 20:44:40 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(t_fdf *fdf)
{
	while (fdf->data.time % 2)
	{
		fdf->data.mtx_loc = transform_mtx(vec3_set(0, 0, 0),
				vec3_set(45, 35.16, 0), vec3_set(1, -1, -10));
		fdf->data.mtx_glob = transform_mtx(fdf->translation,
				fdf->rotation, fdf->scale);
		draw_image(fdf);
		mlx_put_image_to_window(fdf->data.mlx, fdf->data.win.win, fdf->data.img.img, 0, 0);
	}
	fdf->data.time++;
	return (fdf->data.time);
}
