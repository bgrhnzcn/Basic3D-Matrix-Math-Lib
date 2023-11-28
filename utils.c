/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:50:51 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/29 02:37:33 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	deg_to_rad(double deg)
{
	return ((deg / 180) * PI);
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / PI));
}

void	put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*point;

	point = (img->data) + ((img->bits_per_pixel / 8) * x) + (img->size_line * y);
	point[0] = color.alpha;
	point[1] = color.red;
	point[2] = color.green;
	point[3] = color.blue;
}
