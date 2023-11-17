/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:48:26 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/17 16:49:11 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_vertex_data(t_get_vert *ver)
{
	ver->line = get_next_line(ver->obj_file);
	if (ver->line == NULL)
		return (1);
	if (ver->line[0] == 'v')
	{
		ver->datas = ft_split(ver->line, ' ');
		ver->vertices[ver->index].x = strtod(ver->datas[1], NULL);
		ver->vertices[ver->index].y = strtod(ver->datas[2], NULL);
		ver->vertices[ver->index].z = strtod(ver->datas[3], NULL);
		ver->index++;
		free_str_arr(ver->datas);
	}
	free(ver->line);
	return (0);
}

int	get_triangle_data(t_get_tris *tris, t_vec3 *vertices)
{
	tris->line = get_next_line(tris->obj_file);
	if (tris->line == NULL)
		return (1);
	if (tris->line[0] == 'f')
	{
		tris->datas = ft_split(tris->line, ' ');
		tris->tris[tris->index].p1 = vertices[ft_atoi(tris->datas[1]) - 1];
		tris->tris[tris->index].p2 = vertices[ft_atoi(tris->datas[2]) - 1];
		tris->tris[tris->index].p3 = vertices[ft_atoi(tris->datas[3]) - 1];
		tris->index++;
		free_str_arr(tris->datas);
	}
	free(tris->line);
	return (0);
}
