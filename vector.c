/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:58:24 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/04 22:45:43 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_add(t_vec3 *vec1, t_vec3 vec2)
{
	vec1->x += vec2.x;
	vec1->y += vec2.y;
	vec1->z += vec2.z;
}

t_vec3	*vec_add(t_vec3 *vec1, t_vec3 vec2)
{
	t_vec3	*res;
	
	res = malloc(sizeof(t_vec3));
	if (res == NULL)
		return (NULL);
	vec1->x += vec2.x;
	vec1->y += vec2.y;
	vec1->z += vec2.z;
}

double	get_dist(t_vec3 point1, t_vec3 point2)
{
	double	dist_x;
	double	dist_y;
	double	dist_z;

	dist_x = fabs(point1.x - point2.x);
	dist_y = fabs(point1.y - point2.y);
	dist_z = fabs(point1.z - point2.z);
	return (sqrt(pow(dist_x, 2) * pow(dist_y, 2) * pow(dist_z, 2)));
}

double	dot_prod3(t_vec3 vec1, t_vec3 vec2)
{
	double	res;

	res = 0;
	res += vec1.x * vec2.x;
	res += vec1.y * vec2.y;
	res += vec1.z * vec2.z;
	return (res);
}

