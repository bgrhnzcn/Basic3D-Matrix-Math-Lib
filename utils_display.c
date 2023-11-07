/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/08 00:25:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_image(t_data *data)
{
	int				i;
	unsigned int	color;

	color = 0x00FFFFFF;
	i = 0;
	while (i < 7)
	{
		draw_line(&(data->img), data->points[i], data->points[i + 1], color);
		draw_line(&(data->img), data->points[i + 1], data->points[i + 2], color);
		draw_line(&(data->img), data->points[i + 2], data->points[i], color);
		i++;
	}
	draw_line(&(data->img), data->points[0], data->points[data->points_size - 1], color);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 10, 10);
	return (0);
}
