/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/29 18:03:17 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_int_value_of_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (0);
}

int	ft_atoi_hex(const char *str)
{
	int	res;
	int	len;
	int	digit;

	if (str == NULL)
		return (0xFFFFFF00);
	len = ft_strlen(str) - 2;
	digit = 0;
	res = 0;
	while (len > 0)
	{
		res += get_int_value_of_hex(str[len + 1]) * pow(16, digit);
		digit++;
		len--;
	}
	return (res);
}

int	fdf_get_size(t_fdf_data *d, t_fdf_map *map)
{
	map->map_x = 0;
	map->map_y = 0;
	while (1)
	{
		d->line = get_next_line(d->fdf_file);
		if (d->line == NULL)
			return (0);
		d->data = ft_split(d->line, ' ');
		if (d->data == NULL)
		{
			free(d->line);
			return (-1);
		}
		if (map->map_x == 0)
			map->map_x = ft_strarrlen(d->data);
		if (map->map_x != (int)ft_strarrlen(d->data))
		{
			free_str_arr(d->data);
			free(d->line);
			return (-1);
		}
		map->map_y++;
		free_str_arr(d->data);
		free(d->line);
	}
	return (0);
}

int	fdf_map_init_pos_data(t_fdf_data *d, t_fdf_map *map, char *path)
{
	int	res;

	map->vertexes = malloc(sizeof(t_vec3) * map->map_x * map->map_y);
	if (map->vertexes == NULL)
		return (-1);
	d->fdf_file = open(path, O_RDONLY);
	res = fdf_map_get_pos_data(d, map);
	close(d->fdf_file);
	if (res == -1)
	{
		free(map->vertexes);
		return (-1);
	}
	return (0);
}

int	fdf_map_get_pos_data(t_fdf_data *d, t_fdf_map *map)
{
	d->j = 0;
	while (d->j < map->map_y)
	{
		d->line = get_next_line(d->fdf_file);
		if (d->line == NULL)
			return (0);
		d->data = ft_split(d->line, ' ');
		if (d->data == NULL)
		{
			free(d->line);
			return (-1);
		}
		d->i = 0;
		while (d->i < map->map_x)
		{
			map->vertexes[d->i + (map->map_x * d->j)].x = d->i;
			map->vertexes[d->i + (map->map_x * d->j)].y = d->j;
			map->vertexes[d->i + (map->map_x * d->j)].z
				= ft_atoi(d->data[d->i]);
			d->i++;
		}
		d->j++;
		free_str_arr(d->data);
		free(d->line);
	}
	return (0);
}

int	fdf_map_get_color(t_fdf_data *d, t_fdf_map *map)
{
	d->j = 0;
	while (d->j < map->map_y)
	{
		d->line = get_next_line(d->fdf_file);
		if (d->line == NULL)
			return (0);
		d->data = ft_split(d->line, ' ');
		if (d->data == NULL)
		{
			free(d->line);
			return (-1);
		}
		d->i = 0;
		while (d->i < map->map_x)
		{
			map->vertex_colors[d->i + (map->map_x * d->j)].value = ft_atoi_hex(
					ft_strnstr(d->data[d->i], "0x",
						ft_strlen(d->data[d->i])));
			d->i++;
		}
		d->j++;
		free_str_arr(d->data);
		free(d->line);
	}
	return (0);
}

int	fdf_map_init_color(t_fdf_data *d, t_fdf_map *map, char *path)
{
	int	res;

	map->vertex_colors = malloc(sizeof(int) * map->map_x * map->map_y);
	if (map->vertex_colors == NULL)
		return (-1);
	d->fdf_file = open(path, O_RDONLY);
	res = fdf_map_get_color(d, map);
	close(d->fdf_file);
	if (res == -1)
	{
		free(map->vertex_colors);
		return (-1);
	}
	return (0);
}

t_fdf_map	*fdf_map_init(char *fdf_path)
{
	t_fdf_data	data;
	t_fdf_map	*map;
	int			map_status;

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
