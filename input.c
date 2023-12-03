/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/03 17:50:52 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	input(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		if (data->mesh.mesh != NULL)
			free(data->mesh.mesh);
		if (data->map->verteces != NULL)
			free(data->map->verteces);
		if (data->map->vertex_colors != NULL)
			free(data->map->vertex_colors);
		exit(0);
	}
	return (0);
}
