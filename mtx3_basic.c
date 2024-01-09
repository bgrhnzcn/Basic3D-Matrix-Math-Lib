/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx3_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:57:53 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/09 14:59:17 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec)
{
	t_vec3	vec_res;
	t_vec3	col1;
	t_vec3	col2;
	t_vec3	col3;

	col1 = mtx.col1;
	col2 = mtx.col2;
	col3 = mtx.col3;
	vec_res.x = ((vec.x * col1.x) + (vec.y * col1.y) + (vec.z * col1.z));
	vec_res.y = ((vec.x * col2.x) + (vec.y * col2.y) + (vec.z * col2.z));
	vec_res.z = ((vec.x * col3.x) + (vec.y * col3.y) + (vec.z * col3.z));
	return (vec_res);
}
