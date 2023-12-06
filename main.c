/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:40:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 05:21:45 by bgrhnzcn         ###   ########.fr       */
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
		return (error_msg(INVALID_FORMAT), EXIT_FAILURE);
	data.mlx = mlx_init();
	null_checker(&data, data.mlx, MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Test");
	null_checker(&data, data.win, MLX_ERROR);
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	null_checker(&data, data.img.img, MLX_ERROR);
	data.orto_mtx = orto_init();
	data.map = fdf_map_init(obj_path);
	null_checker(&data, data.map, LOAD_ERROR);
	data.img.data = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	null_checker(&data, data.img.data, MLX_ERROR);
	data.time = 0;
	mlx_loop_hook(data.mlx, update, &data);
	mlx_key_hook(data.win, input, &data);
	mlx_loop(data.mlx);
	return (0);
}
