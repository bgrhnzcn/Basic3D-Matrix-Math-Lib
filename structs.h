/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:34:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/11 22:27:21 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	double	min_i;
	double	max_i;
	double	min_o;
	double	max_o;
}	t_map;

typedef union u_vec2
{
	struct
	{
		double	x;
		double	y;
	};
	double	data[2];
}	t_vec2;

typedef union u_vec3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	double	data[3];
}	t_vec3;

typedef union u_tri
{
	struct
	{
		t_vec3	p1;
		t_vec3	p2;
		t_vec3	p3;
	};
	t_vec3	pts[3];
}	t_tri;

typedef union u_vec4
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	double	data[4];
}	t_vec4;

typedef union u_mtx3
{
	struct
	{
		t_vec3	col1;
		t_vec3	col2;
		t_vec3	col3;
	};
	double	data[9];
}	t_mtx3;

typedef union u_mtx4
{
	struct
	{
		t_vec4	col1;
		t_vec4	col2;
		t_vec4	col3;
		t_vec4	col4;
	};
	double	data[16];
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

typedef struct s_mesh
{
	t_tri	*mesh;
	int		tri_count;
}	t_mesh;


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
	t_mtx4			pers_mtx;
	t_mtx4			orto_mtx;
	const t_base3	bases;
	int				tri_count;
	void			*mlx;
	void			*win;
	t_img			img;
	t_tri			*tris;
	t_mesh			mesh;
}	t_data;
