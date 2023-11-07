/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:03:36 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/08 00:25:00 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	mtx3_rot(double x, double y, double z, t_vec3 vec)
{
	t_mtx3	rot;

	x = deg_to_rad(x);
	y = deg_to_rad(y);
	z = deg_to_rad(z);
	rot.col1.x = cos(y) * cos(z);
	rot.col1.y = cos(y) * sin(z);
	rot.col1.z = -sin(y);
	rot.col2.x = (sin(x) * sin(y) * cos(z)) - (cos(x) * sin(z));
	rot.col2.y = (sin(x) * sin(y) * sin(z)) + (cos(x) * cos(z));
	rot.col2.z = (sin(x) * cos(y));
	rot.col3.x = (cos(x) * sin(y) * cos(z)) + (sin(x) * sin(z));
	rot.col3.y = (cos(x) * sin(y) * sin(z)) - (sin(x) * cos(z));
	rot.col3.z = cos(x) * cos(y);
	return (mtx_vec_mul3(rot, vec));
}
