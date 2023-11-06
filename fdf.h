/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/06 22:47:41 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef struct s_mtx4
{
	t_vec4	i;
	t_vec4	j;
	t_vec4	k;
	t_vec4	l;
}	t_mtx4;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_mtx3
{
	t_vec3	col1;
	t_vec3	col2;
	t_vec3	col3;
}	t_mtx3;

typedef struct s_base3
{
	const t_vec3	vec3_i;
	const t_vec3	vec3_j;
	const t_vec3	vec3_k;
	const t_vec3	vec3_null;
	const t_mtx3	mtx3_null;
	const t_mtx3	mtx3_one;
}	t_base3;

typedef struct s_data
{
	t_mtx4			proj_mtx;
	const t_base3	bases;
	t_vec3			*points;
	void			*mng;
	void			*win;
}	t_data;

# define VEC_ZERO 0

# include "utils.c"
# include "vector_op.c"
# include "vector_1.c"
# include "vector_2.c"
# include "matrix.c"

double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
t_vec3	vec_sub(t_vec3	vec1, t_vec3 vec2);
t_vec3	vec_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_mul(t_vec3 vec, double mul);
t_vec3	vec_div(t_vec3 vec, double div);
double	vec_mag(t_vec3 vec);
double	get_dist(t_vec3 point1, t_vec3 point);
double	dot_prod3(t_vec3 vec1, t_vec3 vec2);
t_vec3	cross_prod3(t_vec3 vec1, t_vec3 vec2);
t_vec3	mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
void	set_row(t_mtx3 *mtx, int row_val, t_vec3 row);
t_vec3	get_row(t_mtx3 mtx, int row_val);
t_vec4	mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
t_mtx3	mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);
t_mtx4	mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);
#endif
