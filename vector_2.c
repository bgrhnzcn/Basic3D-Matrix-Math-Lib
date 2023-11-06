/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:17:40 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/06 22:16:19 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	cross_prod3(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec_res;
	vec_res.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	vec_res.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	vec_res.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (vec_res);
}

t_vec3	vec_normalize(t_vec3 vec)
{
	t_vec3	vec_res;

	vec_res = vec_div(vec, vec_mag(vec));
	return (vec_res);
}

