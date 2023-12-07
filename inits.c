/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/07 18:50:16 by bgrhnzcn         ###   ########.fr       */
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

	col1 = vec4_set(2 / (O_RIGHT - O_LEFT), 0, 0, 0);
	col2 = vec4_set(0, 2 / (O_TOP - O_BOT), 0, 0);
	col3 = vec4_set(0, 0, -2 / (O_FAR - O_NEAR), 0);
	col4 = vec4_set(-((O_RIGHT + O_LEFT) / (O_RIGHT - O_LEFT)),
			-((O_TOP + O_BOT) / (O_TOP - O_BOT)),
			-((O_FAR + O_NEAR) / (O_FAR - O_NEAR)), 1);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}

t_mtx4	pers_init(void)
{
	t_mtx4	mtx;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = vec4_set(P_ASPECT_R / (tan(deg_to_rad(P_FOV) / 2)), 0, 0, 0);
	col2 = vec4_set(0, 1 / tan(deg_to_rad(P_FOV) / 2), 0, 0);
	col3 = vec4_set(0, 0,
			-(P_NEAR_CLIP + P_FAR_CLIP) / (P_NEAR_CLIP - P_FAR_CLIP), 1);
	col4 = vec4_set(0, 0,
			(2 * P_FAR_CLIP * P_NEAR_CLIP) / (P_NEAR_CLIP - P_FAR_CLIP), 0);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}

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
	data->mlx = mlx_init();
	null_checker(data, data->mlx, MLX_ERROR);
	data->proj_mtx = orto_init();
	data->translation = vec3_set(0, 0, 0);
	data->rotation = vec3_set(0, 0, 0);
	data->scale = vec3_set(1, 1, 1);
	mlx_do_key_autorepeaton(data->mlx);
	data->map = fdf_map_init(obj_path);
	null_checker(data, data->map, LOAD_ERROR);
	ft_printf("Map Loaded Succesfully...");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Test");
	null_checker(data, data->win, MLX_ERROR);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	null_checker(data, data->img.img, MLX_ERROR);
	data->img.data = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.size_line, &data->img.endian);
	null_checker(data, data->img.data, MLX_ERROR);
}
