/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/08 23:17:21 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtx4	orto_init(void)
{
	t_mtx4	mtx;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = vec4_set(2 / (RIGHT - LEFT), 0, 0, 0);
	col2 = vec4_set(0, 2 / (TOP - BOT), 0, 0);
	col3 = vec4_set(0, 0, -2 / (FAR - NEAR), 0);
	col4 = vec4_set(-((RIGHT + LEFT) / (RIGHT - LEFT)),
	-((TOP + BOT) / (TOP - BOT)), -((FAR + NEAR) / (FAR - NEAR)), 1);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}