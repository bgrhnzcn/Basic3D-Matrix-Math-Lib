/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:52:16 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 15:00:11 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	get_row4(t_mtx4 mtx, int row_val)
{
	t_vec4	vec_res;

	if (row_val == 1)
		vec_res = vec4_set(mtx.col1.x, mtx.col2.x,
				mtx.col3.x, mtx.col4.x);
	else if (row_val == 2)
		vec_res = vec4_set(mtx.col1.y, mtx.col2.y,
				mtx.col3.y, mtx.col4.y);
	else if (row_val == 3)
		vec_res = vec4_set(mtx.col1.z, mtx.col2.z,
				mtx.col3.z, mtx.col4.z);
	else if (row_val == 4)
		vec_res = vec4_set(mtx.col1.w, mtx.col2.w,
				mtx.col3.w, mtx.col4.w);
	else
		vec_res = vec4_set(0, 0, 0, 0);
	return (vec_res);
}

t_vec4	mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec)
{
	t_vec4	vec_res;

	vec_res.x = vec4_dot(vec, get_row4(mtx, 1));
	vec_res.y = vec4_dot(vec, get_row4(mtx, 2));
	vec_res.z = vec4_dot(vec, get_row4(mtx, 3));
	vec_res.w = vec4_dot(vec, get_row4(mtx, 4));
	return (vec_res);
}
