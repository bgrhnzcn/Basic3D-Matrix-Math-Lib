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

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

int	data_counter(int obj_file, char type)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(obj_file);
		if (line == NULL)
			break ;
		if (line[0] == type)
			count++;
		free(line);
	}
	close(obj_file);
	return (count);
}

t_tri	*get_triangles(char *obj_path, t_vec3 *vertices, int *tri_count)
{
	t_get_tris	tris;

	tris.obj_file = open(obj_path, O_RDONLY);
	*tri_count = data_counter(tris.obj_file, 'f');
	close(tris.obj_file);
	tris.tris = malloc(sizeof(t_tri) * *tri_count);
	tris.obj_file = open(obj_path, O_RDONLY);
	tris.index = 0;
	while (1)
	{
		tris.line = get_next_line(tris.obj_file);
		if (tris.line == NULL)
			break ;
		if (tris.line[0] == 'f')
		{
			tris.datas = ft_split(tris.line, ' ');
			tris.tris[tris.index].p1 = vertices[ft_atoi(tris.datas[1]) - 1];
			tris.tris[tris.index].p2 = vertices[ft_atoi(tris.datas[2]) - 1];
			tris.tris[tris.index].p3 = vertices[ft_atoi(tris.datas[3]) - 1];
			tris.index++;
			free_str_arr(tris.datas);
			free(tris.line);
		}
	}
	close(tris.obj_file);
	return (tris.tris);
}

t_vec3	*get_vertices(char *obj_path, int *ver_count)
{
	t_get_vert	ver;

	ver.obj_file = open(obj_path, O_RDONLY);
	*ver_count = data_counter(ver.obj_file, 'v');
	close(ver.obj_file);
	ver.vertices = malloc(sizeof(t_vec3) * *ver_count);
	ver.obj_file = open(obj_path, O_RDONLY);
	ver.index = 0;
	while (1)
	{
		ver.line = get_next_line(ver.obj_file);
		if (ver.line == NULL)
			break ;
		if (ver.line[0] == 'v')
		{
			ver.datas = ft_split(ver.line, ' ');
			ver.vertices[ver.index].x = strtod(ver.datas[1], NULL);
			ver.vertices[ver.index].y = strtod(ver.datas[2], NULL);
			ver.vertices[ver.index].z = strtod(ver.datas[3], NULL);
			ver.index++;
			free_str_arr(ver.datas);
			free(ver.line);
		}
	}
	close(ver.obj_file);
	return (ver.vertices);
}

t_mesh	mesh_init(char *obj_path)
{
	t_mesh	mesh;
	t_vec3	*vertices;

	vertices = get_vertices(obj_path, &mesh.ver_count);
	mesh.mesh = get_triangles(obj_path, vertices, &mesh.tri_count);
	free(vertices);
	return (mesh);
}

int	main(void)
{
	t_data	data;

	data.time = 0;
	data.orto_mtx = orto_init();
	data.mesh = mesh_init("Serdar3.rt");
	//printf("tri_count: %d\n", data.mesh.tri_count);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Test");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	mlx_key_hook(data.win, input, &data);
	mlx_loop_hook(data.mlx, draw_image, &data);
	mlx_loop(data.mlx);
	system("leaks fdf");
	return (0);
}
