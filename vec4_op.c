/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:40:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/08 17:50:43 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	vec4_set(double x, double y, double z, double w)
{
	t_vec4	vec_res;

	vec_res.x = x;
	vec_res.y = y;
	vec_res.z = z;
	vec_res.w = w;
	return (vec_res);
}
