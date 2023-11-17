/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/17 03:09:15 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_tri(t_data *data, t_tri *tris, int j, unsigned int color)
{
	draw_line(&(data)->img, tris[j].pts[0],
		tris[j].pts[1], color);
	draw_line(&(data)->img, tris[j].pts[1],
		tris[j].pts[2], color);
	draw_line(&(data)->img, tris[j].pts[2],
		tris[j].pts[0], color);
}

void	fill_img(t_data *data, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			put_pixel(&(data->img), i, j, color);
			j++;
		}
		i++;
	}
}

int	draw_image(t_data *data)
{
	int		i;
	t_color	color;
	t_tri	*tris;
	t_mtx4	mtx;

	color.value = 0x0000FFFF;
	printf("A: %d, R: %d, G: %d, B: %d\n", color.alpha, color.red, color.green, color.blue);
	i = 0;
	if (data->time % 32 == 0)
	{
		tris = malloc(sizeof(t_tri) * data->mesh.tri_count);
		fill_img(data, 0x00000000);
		while (i < data->mesh.tri_count)
		{
			mtx = loc_to_glob(vec3_set(0, 0, 0), vec3_set(45, 35.264, -90), vec3_set(1, 1, 1));
			tris[i].p1 = vec4_to_vec3(mtx_vec_mul4(data->orto_mtx, mtx_vec_mul4(mtx, vec3_to_vec4(data->mesh.mesh[i].p1, 1))));
			tris[i].p2 = vec4_to_vec3(mtx_vec_mul4(data->orto_mtx, mtx_vec_mul4(mtx, vec3_to_vec4(data->mesh.mesh[i].p2, 1))));
			tris[i].p3 = vec4_to_vec3(mtx_vec_mul4(data->orto_mtx, mtx_vec_mul4(mtx, vec3_to_vec4(data->mesh.mesh[i].p3, 1))));
			tris[i].p1 = vec3_add(tris[i].p1, vec3_set(1, 1, 0));
			tris[i].p2 = vec3_add(tris[i].p2, vec3_set(1, 1, 0));
			tris[i].p3 = vec3_add(tris[i].p3, vec3_set(1, 1, 0));
			tris[i].p1.x *= 0.5 * WIDTH;
			tris[i].p1.y *= 0.5 * HEIGHT;
			tris[i].p2.x *= 0.5 * WIDTH;
			tris[i].p2.y *= 0.5 * HEIGHT;
			tris[i].p3.x *= 0.5 * WIDTH;
			tris[i].p3.y *= 0.5 * HEIGHT;
			draw_tri(data, tris, i, color.value);
			i++;
		}
		free(tris);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	data->time += 1;
	return (0);
}
