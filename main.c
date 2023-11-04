/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:54:01 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/04 20:53:25 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(void)
{
	t_mtx3	mtx_test = {{1, 1, 1}, {0, 1, 0}, {0, 0, 1}};
	t_vec3	vec_test = {1, 2, 3};
	mtx_vec_mul3(mtx_test, &vec_test);
	printf("x: %f, y: %f, z: %f\n", vec_test.x, vec_test.y, vec_test.z);
	printf("%f\n", deg_to_rad(rad_to_deg(2 * M_PI)));
	return (0);
}
