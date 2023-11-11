/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/11 21:10:21 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_tri(t_data *data, int j, unsigned int color)
{
	draw_line(&(data)->img, data->tris[j].pts[0],
		data->tris[j].pts[1], color);
	draw_line(&(data)->img, data->tris[j].pts[1],
		data->tris[j].pts[2], color);
	draw_line(&(data)->img, data->tris[j].pts[2],
		data->tris[j].pts[0], color);
}

void	fill_img(t_data *data, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(&(data->img), i, j, color);
			j++;
		}
		i++;
	}
}

int	draw_image(t_data *data)
{
	int				i;
	unsigned int	color;
	t_tri			*tris;

	color = 0x00FFFFFF;
	i = 0;
	tris = data->tris;
	fill_img(data, 0x00000000);
	while (i < data->tri_count)
	{
		t_vec3	pos;
		t_vec3	rot;
		t_vec3	sca;
		t_mtx4	mtx;

		pos = vec3_set(1, 2, 3);
		rot	= vec3_set(30, 0, 0);
		sca = vec3_set(1, 1, 1);
		mtx = loc_to_glob(pos, rot, sca);
		tris[i].p1 = vec4_to_vec3(mtx_vec_mul4(data->orto_mtx, mtx_vec_mul4(mtx, vec3_to_vec4(tris[i].p1, 1))));
		tris[i].p2 = vec4_to_vec3(mtx_vec_mul4(data->orto_mtx, mtx_vec_mul4(mtx, vec3_to_vec4(tris[i].p2, 1))));
		tris[i].p3 = vec4_to_vec3(mtx_vec_mul4(data->orto_mtx, mtx_vec_mul4(mtx, vec3_to_vec4(tris[i].p3, 1))));
		tris[i].p1.x += 1;
		tris[i].p1.y += 1;
		tris[i].p2.x += 1;
		tris[i].p2.y += 1;
		tris[i].p3.x += 1;
		tris[i].p3.y += 1;
		tris[i].p1.x *= 0.5 * WIDTH;
		tris[i].p1.y *= 0.5 * HEIGHT;
		tris[i].p2.x *= 0.5 * WIDTH;
		tris[i].p2.y *= 0.5 * HEIGHT;
		tris[i].p3.x *= 0.5 * WIDTH;
		tris[i].p3.y *= 0.5 * HEIGHT;
		draw_tri(data, i, color);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
