/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/16 01:35:05 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "structs.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "ft_printf.h"
# include <stdio.h>
# include "get_next_line.h"

# define HEIGHT	1000
# define WIDTH 	1800
# define TOP	-5.
# define BOT	5.
# define RIGHT	5.
# define LEFT	-5.
# define NEAR 	1.
# define FAR 	1000.
# define PI		3.14159265358979323846

static const t_vec3_base	g_vec3_base = {
	.vec3_i = {{.x = 1, .y = 0, .z = 0}},
	.vec3_j = {{.x = 0, .y = 1, .z = 0}},
	.vec3_k = {{.x = 0, .y = 0, .z = 1}},
	.vec3_null = {{0}},
};

static const t_mtx3_base	g_mtx3_base = {
	.mtx3_ident = {{{{1, 0, 0}}, {{0, 1, 0}}, {{0, 0, 1}}}},
	.mtx3_null = {{{{0}}}}
};

double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

t_map	map_init(double min_i, double max_i, double min_o, double max_o);
double	normalize(double val, double min, double max);
double	lerp(double val, double min, double max);
double	map(double val, t_map map);

t_vec2	vec2_set(double x, double y);
t_vec2	vec2_sub(t_vec2	vec1, t_vec2 vec2);
t_vec2	vec2_add(t_vec2 vec1, t_vec2 vec2);
t_vec2	vec2_mul(t_vec2 vec, double mul);
t_vec2	vec2_div(t_vec2 vec, double div);

t_vec3	vec3_set(double x, double y, double z);
t_vec3	vec3_sub(t_vec3	vec1, t_vec3 vec2);
t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_mul(t_vec3 vec, double mul);
t_vec3	vec3_div(t_vec3 vec, double div);

t_vec4	vec4_set(double x, double y, double z, double w);
t_vec4	vec4_add(t_vec4 vec1, t_vec4 vec2);
t_vec4	vec4_sub(t_vec4 vec1, t_vec4 vec2);
t_vec4	vec4_mul(t_vec4 vec, double mul);
t_vec4	vec4_div(t_vec4 vec, double div);

t_vec2	vec2_norm(t_vec2 vec);

double	vec2_dot(t_vec2 vec1, t_vec2 vec2);
double	get_dist2(t_vec2 point1, t_vec2 point);
double	vec2_mag(t_vec2 vec);

t_vec3	vec3_norm(t_vec3 vec);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);

double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
double	get_dist3(t_vec3 point1, t_vec3 point);
double	vec3_mag(t_vec3 vec);

t_vec4	vec4_norm(t_vec4 vec);

double	vec4_dot(t_vec4 vec1, t_vec4 vec2);
double	vec4_mag(t_vec4 vec);

t_vec3	mtx3_trans(double x, double y, double z, t_vec3 vec);
t_vec3	mtx3_scale(double x, double y, double z, t_vec3 vec);
t_vec3	mtx3_rot(double x, double y, double z, t_vec3 vec);
t_mtx4	loc_to_glob(t_vec3 t, t_vec3 r, t_vec3 s);

void	set_row3(t_mtx3 *mtx, int row_val, t_vec3 row);
t_vec3	get_row3(t_mtx3 mtx, int row_val);
t_vec3	mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
t_mtx3	mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);

void	set_row4(t_mtx4 *mtx, int row_val, t_vec4 row);
t_vec4	get_row4(t_mtx4 mtx, int row_val);
t_vec4	mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
t_mtx4	mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);

t_vec4	vec3_to_vec4(t_vec3 vec3, double w);
t_vec3	vec4_to_vec3(t_vec4 vec4);

void	put_pixel(t_img *img, int x, int y, unsigned int color);
void	draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
void	draw_tri(t_data *data, t_tri *tris, int j, unsigned int color);
int		draw_image(t_data *data);
void	fill_img(t_data *data, unsigned int color);

int		input(int keycode, t_data *data);

void	free_str_arr(char **str_arr);
int		data_counter(int obj_file, char type);
int		get_vertex_data(t_get_vert *ver);
t_vec3	*get_vertices(char *obj_path, int *ver_count);
int		get_triangle_data(t_get_tris *tris, t_vec3 *vertices);
t_tri	*get_triangles(char *obj_path, t_vec3 *vertices, int *tri_count);
t_mesh	mesh_init(char *obj_path);

t_mtx4	orto_init(void);
t_mtx4	pers_init(void);

#endif
