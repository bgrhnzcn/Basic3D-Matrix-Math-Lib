/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:54:01 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/08 01:05:37 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_data	data;
	t_vec3	points[8];
	t_mtx3	orto;
	int		i;

	i = 0;
	orto = orto_init();
	data.points_size = 8;
	points[0] = vec3_set(100, 100, 100);
	points[1] = vec3_set(100, 100, 200);
	points[2] = vec3_set(100, 200, 100);
	points[3] = vec3_set(100, 200, 200);
	points[4] = vec3_set(200, 100, 100);
	points[5] = vec3_set(200, 100, 200);
	points[6] = vec3_set(200, 200, 100);
	points[7] = vec3_set(200, 200, 200);
	while (i < data.points_size)
	{
		points[i] = mtx3_rot(0, 0, 90, points[i]);
		points[i] = mtx_vec_mul3(orto, points[i]);
		i++;
	}
	data.points = points;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Test");
	data.img.img = mlx_new_image(data.mlx, 500, 500);
	data.img.data = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	draw_image(&data);
	mlx_loop(data.mlx);
	system("leaks fdf");
	return (0);
}
