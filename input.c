/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/13 16:36:23 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		//if (data->mesh.mesh != NULL)
		//	free(data->mesh.mesh);
		exit(0);
	}
	return (0);
}
