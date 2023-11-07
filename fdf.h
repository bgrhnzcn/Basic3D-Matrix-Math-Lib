/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/08 01:02:01 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>


# define HEIGHT		500
# define WIDTH		500
# define NEAR_PLANE	10
# define FAR_PLANE	100
# define PI			3.14159265358979323846

typedef struct s_map
{
	double	min_i;
	double	max_i;
	double	min_o;
	double	max_o;
}	t_map;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_tri
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
}	t_tri;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef struct s_mtx3
{
	t_vec3	col1;
	t_vec3	col2;
	t_vec3	col3;
}	t_mtx3;

typedef struct s_mtx4
{
	t_vec4	i;
	t_vec4	j;
	t_vec4	k;
	t_vec4	l;
}	t_mtx4;

typedef struct s_base3
{
	const t_vec3	vec3_i;
	const t_vec3	vec3_j;
	const t_vec3	vec3_k;
	const t_vec3	vec3_null;
	const t_mtx3	mtx3_null;
	const t_mtx3	mtx3_ident;
}	t_base3;

typedef	struct s_img
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_mtx4			proj_mtx;
	const t_base3	bases;
	t_vec3			*points;
	int				points_size;
	void			*mlx;
	void			*win;
	t_img			img;
}	t_data;

# include "utils.c"
# include "utils_bresenham_line.c"
# include "utils_maps.c"
# include "utils_display.c"
# include "vec2_op.c"
# include "vec2_double.c"
# include "vec2_vec2.c"
# include "vec3_op.c"
# include "vec3_double.c"
# include "vec3_vec3.c"
# include "matrix.c"
# include "utils_mtx.c"
# include "utils_rot.c"

double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

t_map	map_init(double min_i, double max_i, double min_o, double max_o);
double	normalize(double val, double min, double max);
double	lerp(double val, double min, double max);
double	map(double val, t_map map);

t_vec3	vec3_set(double x, double y, double z);
t_vec3	vec3_sub(t_vec3	vec1, t_vec3 vec2);
t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_mul(t_vec3 vec, double mul);
t_vec3	vec3_div(t_vec3 vec, double div);
t_vec3	vec3_norm(t_vec3 vec);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);
double	vec3_mag(t_vec3 vec);
double	get_dist3(t_vec3 point1, t_vec3 point);
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);

t_vec2	vec2_set(double x, double y);
t_vec2	vec2_sub(t_vec2	vec1, t_vec2 vec2);
t_vec2	vec2_add(t_vec2 vec1, t_vec2 vec2);
t_vec2	vec2_mul(t_vec2 vec, double mul);
t_vec2	vec2_div(t_vec2 vec, double div);
t_vec2	vec2_norm(t_vec2 vec);
double	vec2_mag(t_vec2 vec);
double	get_dist2(t_vec2 point1, t_vec2 point);

t_mtx3	proj_orto_init(void);
t_vec3	mtx3_rot(double x, double y, double z, t_vec3 vec);

t_vec3	mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
void	set_row(t_mtx3 *mtx, int row_val, t_vec3 row);
t_vec3	get_row(t_mtx3 mtx, int row_val);
t_vec4	mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
t_mtx3	mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);
t_mtx4	mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);

void	draw_line_low(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
void	draw_line_high(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
void	draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, unsigned int color);
int		draw_image(t_data *data);
#endif
