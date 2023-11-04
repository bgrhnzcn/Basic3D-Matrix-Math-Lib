/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:57:53 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/04 20:58:48 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mtx_vec_mul3(t_mtx3 mtx, t_vec3 *vec)
{
	t_vec3	*temp;
	t_vec3	col1;
	t_vec3	col2;
	t_vec3	col3;

	temp = malloc(sizeof(t_vec3));
	if (temp == NULL)
		return ;
	col1 = mtx.col1;
	col2 = mtx.col2;
	col3 = mtx.col3;
	temp->x = ((vec->x * col1.x) + (vec->y * col1.y) + (vec->z * col1.z));
	temp->y = ((vec->x * col2.x) + (vec->y * col2.y) + (vec->z * col2.z));
	temp->z = ((vec->x * col3.x) + (vec->y * col3.y) + (vec->z * col3.z));
	vec->x = temp->x;
	vec->y = temp->y;
	vec->z = vec->z;
	free(temp);
}
