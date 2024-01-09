/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 21:38:00 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	input_helper(int keycode, t_fdf *fdf)
{
	if (keycode == Q_KEY)
		fdf->rotation = vec3_add(fdf->rotation, vec3_set(0, 1, 0));
	if (keycode == E_KEY)
		fdf->rotation = vec3_add(fdf->rotation, vec3_set(0, -1, 0));
	if (keycode == R_KEY)
		fdf->rotation = vec3_add(fdf->rotation, vec3_set(1, 0, 0));
	if (keycode == T_KEY)
		fdf->rotation = vec3_add(fdf->rotation, vec3_set(-1, 0, 0));
	if (keycode == O_KEY)
		fdf->data.proj_mtx = orto_init(set_ort_conf(vec4_set(
						O_TOP, O_BOT, O_RIGHT, O_LEFT),
					vec2_set(O_NEAR, O_FAR)));
	if (keycode == P_KEY)
		fdf->data.proj_mtx = pers_init(set_pers_conf(
					vec4_set(P_NEAR_CLIP, P_FAR_CLIP, P_FOV, P_ASPECT_R)));
	return (0);
}

int	input(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		terminate_prog(fdf, EXIT_SUCCESS);
	if (keycode == W_KEY)
		fdf->translation = vec3_add(fdf->translation, vec3_set(0, -0.2, 0));
	if (keycode == A_KEY)
		fdf->translation = vec3_add(fdf->translation, vec3_set(-0.2, 0, 0));
	if (keycode == S_KEY)
		fdf->translation = vec3_add(fdf->translation, vec3_set(0, 0.2, 0));
	if (keycode == D_KEY)
		fdf->translation = vec3_add(fdf->translation, vec3_set(0.2, 0, 0));
	if (keycode == F_KEY)
		fdf->translation = vec3_add(fdf->translation, vec3_set(0, 0, 0.2));
	if (keycode == G_KEY)
		fdf->translation = vec3_add(fdf->translation, vec3_set(0, 0, -0.2));
	if (keycode == Z_KEY)
		fdf->scale = vec3_add(fdf->scale, vec3_set(1, 1, 1));
	if (keycode == X_KEY)
		fdf->scale = vec3_add(fdf->scale, vec3_set(-1, -1, -1));
	input_helper(keycode, fdf);
	return (0);
}

int	terminate_prog(t_fdf *fdf, int exit_state)
{
	if (fdf->data.img.img != NULL)
		mlx_destroy_image(fdf->data.mlx, fdf->data.img.img);
	if (fdf->data.win.win != NULL)
		mlx_destroy_window(fdf->data.mlx, fdf->data.win.win);
	if (fdf->data.mlx != NULL)
		free(fdf->data.mlx);
	if (fdf->map != NULL && fdf->map->verteces != NULL)
		free(fdf->map->verteces);
	if (fdf->map != NULL && fdf->map->vertex_colors != NULL)
		free(fdf->map->vertex_colors);
	if (fdf->map != NULL)
		free(fdf->map);
	free(fdf);
	system("MallocStackLogging=1 leaks fdf");
	exit(exit_state);
	return (0);
}
