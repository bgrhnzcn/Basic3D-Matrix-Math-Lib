/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/04 22:45:50 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

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

typedef struct s_data
{
	t_mtx4	*proj_mtx;
	t_vec3	**points;
	void	*mng;
	void	*win;
}	t_data;

# include "utils.c"
# include "vector.c"
# include "matrix.c"

double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
double	get_dist(t_vec3 point1, t_vec3 point);
void	mtx_vec_mul3(t_mtx3 mtx, t_vec3 *vec);
t_vec4	mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
t_mtx3	mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);
t_mtx4	mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);
t_vec3	cross_prod(t_vec3 *vec1, t_vec3 *vec2);
t_vec3	*vec_add(t_vec3 *vec1, t_vec3 vec2);
double	dot_prod3(t_vec3 vec1, t_vec3 vec2);
#endif
