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

//void	bases_init(t_data *data)
//{
//	data->bases.vec3_i = vec3_set(1, 0, 0);
//	data->bases.vec3_j = vec3_set(0, 1, 0);
//	data->bases.vec3_k = vec3_set(0, 0, 1);
//	data->bases.vec3_null = vec3_set(0, 0, 0);
//	data->bases.mtx3_null.col1 = data->bases.vec3_null;
//	data->bases.mtx3_null.col2 = data->bases.vec3_null;
//	data->bases.mtx3_null.col3 = data->bases.vec3_null;
//	data->bases.mtx3_ident.col1 = data->bases.vec3_i;
//	data->bases.mtx3_ident.col2 = data->bases.vec3_j;
//	data->bases.mtx3_ident.col3 = data->bases.vec3_k;
//}

t_mesh	mesh_init(char *obj_path)
{
	t_mesh	mesh;
	char	buff;
	int		obj_file;
	int		read_state;

	obj_file = open(obj_path, O_RDONLY);
	mesh.tri_count = 0;
	read_state = 1;
	while (read_state > 0)
	{
		read_state = read(obj_file, &buff, 1);
		if (buff == 'f')
			mesh.tri_count++;
		printf("Working...\n");
	}
	mesh.mesh = malloc(sizeof(t_tri) * mesh.tri_count);
	return (mesh);
}

int	main(void)
{
	t_data	data;

	data.orto_mtx = orto_init();
	//data.mesh = mesh_init("Serdar3.rt");
	//printf("tri_count: %d\n", data.mesh.tri_count);
	data.tri_count = 6;
	data.tris = tris_init();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Test");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	mlx_key_hook(data.win, input, &data);
	draw_image(&data);
	mlx_loop(data.mlx);
	system("leaks fdf");
	return (0);
}
