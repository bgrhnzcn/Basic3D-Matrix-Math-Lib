/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:52:16 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/08 20:58:12 by bgrhnzcn         ###   ########.fr       */
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

void	set_row4(t_mtx4 *mtx, int row_val, t_vec4 row)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		mtx->data[i * row_val] = row.data[i];
		i++;
	}
}

t_vec4	mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec)
{
	t_vec4	vec_res;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = mtx.col1;
	col2 = mtx.col2;
	col3 = mtx.col3;
	col4 = mtx.col4;
	vec_res.x = vec4_dot(vec, col1);
	vec_res.y = vec4_dot(vec, col2);
	vec_res.z = vec4_dot(vec, col3);
	vec_res.w = vec4_dot(vec, col4);
	return (vec_res);
}