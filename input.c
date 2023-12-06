/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 05:14:13 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	input(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		terminate_prog(data, EXIT_SUCCESS);
	return (0);
}

void	terminate_prog(t_data *data, int exit_state)
{
	if (data->img.img != NULL)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		free(data->mlx);
	if (data->map->verteces != NULL)
		free(data->map->verteces);
	if (data->map->vertex_colors != NULL)
		free(data->map->vertex_colors);
	if (data->map != NULL)
		free(data->map);
	exit(exit_state);
}
