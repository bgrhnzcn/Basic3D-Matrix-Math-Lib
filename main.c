/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:54:01 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/06 22:47:35 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double map(double x, double min_i, double max_i, double min_o, double max_o)
{
  return (((x - min_i) * (max_o - min_o)) / (max_i - min_i)) + min_o;
}

int	main(void)
{
	t_mtx3	mtx_test = {{1, 1, 1}, {0, 1, 0}, {0, 0, 1}};
	t_mtx3	mtx_test2 = {{1, 1, 1}, {0, 1, 0}, {0, 0, 1}};
	t_mtx3	mtx_res;
	mtx_res = mtx_mtx_mul3(mtx_test, mtx_test2);
	//t_vec3	vec_test = {1, 2, 3};
	//t_vec3	res;
	//res = cross_prod3(mtx_test.col1, vec_test);
	//mtx_vec_mul3(mtx_test, &vec_test);
	printf("col1  x: %f, y: %f, z: %f\n", mtx_res.col1.x, mtx_res.col1.y, mtx_res.col1.z);
	printf("col2  x: %f, y: %f, z: %f\n", mtx_res.col2.x, mtx_res.col2.y, mtx_res.col2.z);
	printf("col3  x: %f, y: %f, z: %f\n", mtx_res.col3.x, mtx_res.col3.y, mtx_res.col3.z);
	printf("map-in: %f, map-out: %f\n", (double)300, map(300, 200, 500, 10, 20));
	//printf("%f\n", deg_to_rad(rad_to_deg(2 * M_PI)));
	//system("leaks fdf");
	return (0);
}
