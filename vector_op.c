/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:22:36 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/06 22:00:30 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	set_vec3(double x, double y, double z)
{
	t_vec3	vec_res;

	vec_res.x = x;
	vec_res.y = y;
	vec_res.z = z;
	return (vec_res);
}

t_vec3	vec_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec_res;
	
	vec_res.x = vec1.x + vec2.x;
	vec_res.y = vec1.y + vec2.y;
	vec_res.z = vec1.z + vec2.z;
	return (vec_res);
}

t_vec3	vec_sub(t_vec3	vec1, t_vec3 vec2)
{
	t_vec3	vec_res;

	vec_res.x = vec1.x - vec2.x;
	vec_res.y = vec1.y - vec2.y;
	vec_res.z = vec1.z - vec2.z;
	return (vec_res);
}

t_vec3	vec_mul(t_vec3 vec, double mul)
{
	t_vec3	vec_res;

	vec_res.x = vec.x * mul;
	vec_res.y = vec.y * mul;
	vec_res.z = vec.z * mul;
	return (vec_res);
}

t_vec3	vec_div(t_vec3 vec, double div)
{
	t_vec3	vec_res;

	vec_res.x = vec.x / div;
	vec_res.y = vec.y / div;
	vec_res.z = vec.z / div;
	return (vec_res);
}
