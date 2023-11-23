/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:40:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/23 22:31:19 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	*obj_path;

	if (argc != 2)
		return (0);
	obj_path = argv[1];
	if (!ft_strnstr(obj_path, ".fdf", ft_strlen(obj_path)))
	{
		printf("Error: Invalid file format\n");
		return (EXIT_FAILURE);
	}
	data.time = 0;
	data.orto_mtx = orto_init();
	//data.map = fdf_map_init(obj_path);
	data.mesh = mesh_init(obj_path);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Test");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	mlx_key_hook(data.win, input, &data);
	mlx_loop_hook(data.mlx, draw_image, &data);
	mlx_loop(data.mlx);
	return (0);
}
