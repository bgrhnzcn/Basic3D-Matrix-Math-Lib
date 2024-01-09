/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 19:24:19 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_map	*fdf_map_init(char *fdf_path)
{
	t_fdf_data	data;
	t_fdf_map	*map;
	int			map_status;

	ft_printf("Loading Map...\n");
	map = malloc(sizeof(t_fdf_map));
	if (map == NULL)
		return (NULL);
	data.fdf_file = open(fdf_path, O_RDONLY);
	map_status = fdf_get_size(&data, map);
	close(data.fdf_file);
	if (map_status == -1)
		return (NULL);
	if (map_status == 0 && map->map_y == 0)
		return (NULL);
	if (fdf_map_init_pos_data(&data, map, fdf_path) == -1)
		return (NULL);
	if (fdf_map_init_color(&data, map, fdf_path) == -1)
		return (NULL);
	return (map);
}

void	main_init(t_data *data, char *obj_path)
{
	data->win.height = HEIGHT;
	data->win.width = WIDTH;
	data->mlx = mlx_init();
	null_checker(data, data->mlx, MLX_ERROR);
	data->proj_mtx = orto_init(set_ort_conf(vec4_set(
					O_TOP, O_BOT, O_RIGHT, O_LEFT), vec2_set(O_NEAR, O_FAR)));
	data->translation = vec3_set(0, 0, 0);
	data->rotation = vec3_set(0, 0, 0);
	data->scale = vec3_set(1, 1, 1);
	mlx_do_key_autorepeaton(data->mlx);
	data->map = fdf_map_init(obj_path);
	null_checker(data, data->map, LOAD_ERROR);
	ft_printf("Map Loaded Succesfully...\n");
	data->win.win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Test");
	null_checker(data, data->win.win, MLX_ERROR);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	null_checker(data, data->img.img, MLX_ERROR);
	data->img.data = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.size_line, &data->img.endian);
	null_checker(data, data->img.data, MLX_ERROR);
}
