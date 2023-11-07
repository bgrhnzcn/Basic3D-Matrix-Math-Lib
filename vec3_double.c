/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:58:24 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/07 14:03:24 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_dist3(t_vec3 point1, t_vec3 point2)
{
	double	dist_x;
	double	dist_y;
	double	dist_z;

	dist_x = fabs(point1.x - point2.x);
	dist_y = fabs(point1.y - point2.y);
	dist_z = fabs(point1.z - point2.z);
	return (sqrt(pow(dist_x, 2) * pow(dist_y, 2) * pow(dist_z, 2)));
}

double	vec3_mag(t_vec3 vec)
{
	t_vec3	vec_null;

	vec_null.x = 0;
	vec_null.y = 0;
	vec_null.z = 0;
	return (get_dist3(vec_null, vec));
}

double	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	double	res;

	res = 0;
	res += vec1.x * vec2.x;
	res += vec1.y * vec2.y;
	res += vec1.z * vec2.z;
	return (res);
}
