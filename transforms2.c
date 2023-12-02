/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:15:51 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/02 21:12:50 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtx4	transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s)
{
	t_mtx4	mtx;

	r.x = deg_to_rad(r.x);
	r.y = deg_to_rad(r.y);
	r.z = deg_to_rad(r.z);
	mtx.col1 = vec4_set(
			cos(r.y) * cos(r.z),
			cos(r.y) * sin(r.z),
			-sin(r.y), 0);
	mtx.col2 = vec4_set(
			(sin(r.x) * sin(r.y) * cos(r.z)) - (cos(r.x) * sin(r.z)),
			(sin(r.x) * sin(r.y) * sin(r.z)) + (cos(r.x) * cos(r.z)),
			(sin(r.x) * cos(r.y)), 0);
	mtx.col3 = vec4_set(
			(cos(r.x) * sin(r.y) * cos(r.z)) + (sin(r.x) * sin(r.z)),
			(cos(r.x) * sin(r.y) * sin(r.z)) - (sin(r.x) * cos(r.z)),
			cos(r.x) * cos(r.y), 0);
	mtx.col1 = vec4_mul(mtx.col1, s.x);
	mtx.col2 = vec4_mul(mtx.col2, s.y);
	mtx.col3 = vec4_mul(mtx.col3, s.z);
	mtx.col4 = vec4_set(t.x, t.y, t.z, 1);
	return (mtx);
}
