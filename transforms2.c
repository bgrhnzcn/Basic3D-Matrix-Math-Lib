/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:15:51 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/29 01:26:18 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtx4	loc_to_glob(t_vec3 t, t_vec3 r, t_vec3 s)
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

t_vec3	clip_to_screen(t_vec3 point)
{
	point = vec3_add(point, vec3_set(1, 1, 0));
	point.x *= 0.5 * WIDTH;
	point.y *= 0.5 * HEIGHT;
	return (point);
}

t_vec3	glob_to_clip(t_data *d, t_mtx4 mtx, int current)
{
	return (vec4_to_vec3(mtx_vec_mul4(d->orto_mtx, mtx_vec_mul4(mtx,
					vec3_to_vec4(d->map->vertexes[current], 1)))));
}
