/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/10 01:13:23 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT	900
# define WIDTH 	900
# define TOP	-5.
# define BOT	5.
# define RIGHT	5.
# define LEFT	-5.
# define NEAR 	1
# define FAR 	1000.
# define PI		3.14159265358979323846

# include "structs.h"
# include <math.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include "utils.c"
# include "input.c"
# include "utils_bresenham_line.c"
# include "utils_maps.c"
# include "vec2_op.c"
# include "vec2_double.c"
# include "vec2_vec2.c"
# include "vec3_op.c"
# include "vec3_double.c"
# include "vec3_vec3.c"
# include "vec4_op.c"
# include "vec4_double.c"
# include "vec_conv.c"
# include "mtx3_basic.c"
# include "mtx4_basic.c"
# include "projections.c"
# include "transforms.c"
# include "utils_display.c"

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
void	draw_line_low(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
void	draw_line_high(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
void	draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
void	draw_tri(t_data *data, int j, unsigned int color);
int		draw_image(t_data *data);
void	fill_img(t_data *data, unsigned int color);

int		input(int keycode, t_data *data);

t_mtx4	orto_init(void);

#endif
