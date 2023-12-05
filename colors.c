/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:34:21 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/05 18:44:23 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	set_color(__uint8_t a, __uint8_t r, __uint8_t g, __uint8_t b)
{
	t_color	color;

	color.alpha = a;
	color.red = r;
	color.green = g;
	color.blue = b;
	return (color);
}

t_color	get_gradient_val(t_color from, t_color to, double value)
{
	t_color	color;
	double	temp_red;
	double	temp_green;
	double	temp_blue;

	temp_red = lerp(value, from.red, to.red);
	if (temp_red >= 255)
		color.red = 255;
	else if (temp_red <= 0)
		color.red = 0;
	else
		color.red = temp_red;
	temp_green = lerp(value, from.green, to.green);
	if (temp_green >= 255)
		color.green = 255;
	else if (temp_green <= 0)
		color.green = 0;
	else
		color.green = temp_green;
	temp_blue = lerp(value, from.blue, to.blue);
	if (temp_blue >= 255)
		color.blue = 255;
	else if (temp_blue <= 0)
		color.blue = 0;
	else
		color.blue = temp_blue;
	return (color);
}

t_gradient	set_gradient(t_color from, t_color to)
{
	t_gradient	grad;

	grad.from = from;
	grad.to = to;
	return (grad);
}

t_gradient	inv_gradient(t_gradient in)
{
	t_gradient	out;

	out.from = in.to;
	out.to = in.from;
	return (out);
}
