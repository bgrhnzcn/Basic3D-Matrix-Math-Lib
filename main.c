/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0.523/11/03 21:54:01 by buozcan           #+#    #+#             */
/*   Updated: 0.523/11/08 22:29:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tri	*tris_init(void)
{
	t_tri	*temp;

	temp = malloc(sizeof(t_tri) * 6);
	temp[0].p1 = vec3_set(-0.5, 0.5, -0.5);
	temp[0].p2 = vec3_set(-0.5, -0.5, -0.5);
	temp[0].p3 = vec3_set(0.5, -0.5, -0.5);

	temp[1].p1 = vec3_set(-0.5, 0.5, -0.5);
	temp[1].p2 = vec3_set(0.5, -0.5, -0.5);
	temp[1].p3 = vec3_set(0.5, 0.5, -0.5);

	temp[2].p1 = vec3_set(-0.5, -0.5, -0.5);
	temp[2].p2 = vec3_set(-0.5, -0.5, 0.5);
	temp[2].p3 = vec3_set(0.5, -0.5, 0.5);

	temp[3].p1 = vec3_set(-0.5, -0.5, -0.5);
	temp[3].p2 = vec3_set(0.5, -0.5, 0.5);
	temp[3].p3 = vec3_set(0.5, -0.5, -0.5);

	temp[4].p1 = vec3_set(0.5, 0.5, -0.5);
	temp[4].p2 = vec3_set(0.5, -0.5, -0.5);
	temp[4].p3 = vec3_set(0.5, -0.5, 0.5);

	temp[5].p1 = vec3_set(0.5, 0.5, -0.5);
	temp[5].p2 = vec3_set(0.5, -0.5, 0.5);
	temp[5].p3 = vec3_set(0.5, 0.5, 0.5);
	return (temp);
}

int	main(void)
{
	t_data	data;

	data.orto_mtx = orto_init();
	data.tri_count = 6;
	data.tris = tris_init();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Test");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	mlx_key_hook(data.win, exit_app, &data);
	draw_image(&data);
	mlx_loop(data.mlx);
	system("leaks fdf");
	return (0);
}
