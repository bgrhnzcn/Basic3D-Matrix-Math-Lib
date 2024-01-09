/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 18:26:12 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	input_helper(int keycode, t_data *data)
{
	if (keycode == Q_KEY)
		data->rotation = vec3_add(data->rotation, vec3_set(0, 1, 0));
	if (keycode == E_KEY)
		data->rotation = vec3_add(data->rotation, vec3_set(0, -1, 0));
	if (keycode == R_KEY)
		data->rotation = vec3_add(data->rotation, vec3_set(1, 0, 0));
	if (keycode == T_KEY)
		data->rotation = vec3_add(data->rotation, vec3_set(-1, 0, 0));
	if (keycode == O_KEY)
		data->proj_mtx = orto_init(set_ort_conf(vec4_set(
						O_TOP, O_BOT, O_RIGHT, O_LEFT),
					vec2_set(O_NEAR, O_FAR)));
	if (keycode == P_KEY)
		data->proj_mtx = pers_init(set_pers_conf(
					vec4_set(P_NEAR_CLIP, P_FAR_CLIP, P_FOV, P_ASPECT_R)));
	return (0);
}

int	input(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		terminate_prog(data, EXIT_SUCCESS);
	if (keycode == W_KEY)
		data->translation = vec3_add(data->translation, vec3_set(0, -0.2, 0));
	if (keycode == A_KEY)
		data->translation = vec3_add(data->translation, vec3_set(-0.2, 0, 0));
	if (keycode == S_KEY)
		data->translation = vec3_add(data->translation, vec3_set(0, 0.2, 0));
	if (keycode == D_KEY)
		data->translation = vec3_add(data->translation, vec3_set(0.2, 0, 0));
	if (keycode == F_KEY)
		data->translation = vec3_add(data->translation, vec3_set(0, 0, 0.2));
	if (keycode == G_KEY)
		data->translation = vec3_add(data->translation, vec3_set(0, 0, -0.2));
	if (keycode == Z_KEY)
		data->scale = vec3_add(data->scale, vec3_set(1, 1, 1));
	if (keycode == X_KEY)
		data->scale = vec3_add(data->scale, vec3_set(-1, -1, -1));
	input_helper(keycode, data);
	return (0);
}

int	terminate_prog(t_data *data, int exit_state)
{
	if (data->img.img != NULL)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win.win != NULL)
		mlx_destroy_window(data->mlx, data->win.win);
	if (data->mlx != NULL)
		free(data->mlx);
	if (data->map != NULL && data->map->verteces != NULL)
		free(data->map->verteces);
	if (data->map != NULL && data->map->vertex_colors != NULL)
		free(data->map->vertex_colors);
	if (data->map != NULL)
		free(data->map);
	free(data);
	exit(exit_state);
	return (0);
}
