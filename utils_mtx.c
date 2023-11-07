/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mtx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/07 15:56:09 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtx3	orto_init(void)
{
	t_mtx3	mtx;
	t_vec3	col1;
	t_vec3	col2;
	t_vec3	col3;

	col1 = vec3_set(1, 0, 0);
	col2 = vec3_set(0, 1, 0);
	col3 = vec3_set(0, 0, 0);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	return (mtx);
}