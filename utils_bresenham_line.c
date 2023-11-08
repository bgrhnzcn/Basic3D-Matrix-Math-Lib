/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bresenham_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:06:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/08 21:24:37 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_low(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color)
{
	t_vec2	delta;
	double	inc;
	double	side_check;
	double	x;
	double	y;

	delta.x = pt2.x - pt1.x;
	delta.y = pt2.y - pt1.y;
	inc = 1;
	if (delta.y < 0)
	{
		inc = -1;
		delta.y = -delta.y;
	}
	side_check = (2 * delta.y) - delta.x;
	y = pt1.y;
	x = pt1.x;
	while (x < pt2.x && x < WIDTH && x > 0 )
	{
		if (y <= HEIGHT && y >= 0 && x <= WIDTH && x >= 0)
			put_pixel(img, x, y, color);
		if (side_check > 0)
		{
			y += inc;
			side_check = side_check + (2 * (delta.y - delta.x));
		}
		else
			side_check = side_check + (2 * delta.y);
		x++;
	}
}

void	draw_line_high(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color)
{
	t_vec2	delta;
	double	inc;
	double	side_check;
	double	x;
	double	y;

	delta.x = pt2.x - pt1.x;
	delta.y = pt2.y - pt1.y;
	inc = 1;
	if (delta.x < 0)
	{
		inc = -1;
		delta.x = -delta.x;
	}
	side_check = (2 * delta.x) - delta.y;
	x = pt1.x;
	y = pt1.y;
	while (y <= pt2.y)
	{
		if (y <= HEIGHT && y >= 0 && x <= WIDTH && x >= 0)
			put_pixel(img, x, y, color);
		if (side_check > 0)
		{
			x += inc;
			side_check = side_check + (2 * (delta.x - delta.y));
		}
		else
			side_check = side_check + (2 * delta.x);
		y++;
	}
}

void	draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color)
{
	if (fabs(pt2.y - pt1.y) < fabs(pt2.x - pt1.x))
	{
		if (pt1.x > pt2.x)
			draw_line_low(img, pt2, pt1, color);
		else
			draw_line_low(img, pt1, pt2, color);
	}
	else
	{
		if (pt1.y > pt2.y)
			draw_line_high(img, pt2, pt1, color);
		else
			draw_line_high(img, pt1, pt2, color);
	}
}
