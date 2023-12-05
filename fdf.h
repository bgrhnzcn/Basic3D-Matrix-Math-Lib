/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/12/05 17:21:35 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "structs.h"
# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"

//Special include to work on multi platform.
# ifdef __linux__
#  include <X11/keysym.h>
#  define ESC_KEY 65307
# else
#  define ESC_KEY 53
# endif

//Camera Options
# define HEIGHT		1000
# define WIDTH 		1000
# define TOP		-10.
# define BOT		10.
# define RIGHT		-10.
# define LEFT		10.
# define NEAR 		1.
# define FAR 		1000.

//Math Value
# define PI			3.14159265358979323846

//# define VEC3_NULL	(t_vec3){{.x = 0., .y = 0., .z = 0.}}
//# define VEC3_ONE	(t_vec3){{.x = 1., .y = 1., .z = 1.}}
void	vec3_test(t_vec3 *vec, double x, double y, double z);

//Gets numbers of strings inside of string arrays. String arrays must be null-ended.
size_t		ft_strarrlen(char **arr);

//Degree to Radian conversions.
double		deg_to_rad(double deg);
//Radian to Degree conversions.
double		rad_to_deg(double rad);

//------- Fucntion to help reformat value ranges ---------

//Initializes map from given values to use inside map function.
t_map		map_init(double min_i, double max_i, double min_o, double max_o);
//Gives normalized value (0 to 1 range value) of given value inside specified range.
double		normalize(double val, double min, double max);
//Gets normalized value (0 to 1 range value) and gives the value corresponding on specified range.
double		lerp(double val, double min, double max);
//This function uses t_map to convert value from one range to another.
double		map(double val, t_map map);

//Basic 2D vector operations.
t_vec2		vec2_set(double x, double y);
t_vec2		vec2_sub(t_vec2	vec1, t_vec2 vec2);
t_vec2		vec2_add(t_vec2 vec1, t_vec2 vec2);
t_vec2		vec2_mul(t_vec2 vec, double mul);
t_vec2		vec2_div(t_vec2 vec, double div);

//Basic 3D vector operations.
t_vec3		vec3_set(double x, double y, double z);
t_vec3		vec3_sub(t_vec3	vec1, t_vec3 vec2);
t_vec3		vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_mul(t_vec3 vec, double mul);
t_vec3		vec3_div(t_vec3 vec, double div);

//Basic 4D vector operations.
t_vec4		vec4_set(double x, double y, double z, double w);
t_vec4		vec4_add(t_vec4 vec1, t_vec4 vec2);
t_vec4		vec4_sub(t_vec4 vec1, t_vec4 vec2);
t_vec4		vec4_mul(t_vec4 vec, double mul);
t_vec4		vec4_div(t_vec4 vec, double div);

//This function normalizes 2D vectors. For detailed info https://en.wikipedia.org/wiki/Unit_vector
t_vec2		vec2_norm(t_vec2 vec);

//2D versions of dot product. For detailed info https://en.wikipedia.org/wiki/Dot_product
double		vec2_dot(t_vec2 vec1, t_vec2 vec2);
//2D verison of distance function.
double		get_dist2(t_vec2 point1, t_vec2 point);
//2D version of magnitude function. This function gives lenght of 2D vectors.
double		vec2_mag(t_vec2 vec);

//This function normalizes 3D vectors. For detailed info https://en.wikipedia.org/wiki/Unit_vector
t_vec3		vec3_norm(t_vec3 vec);
//This function gives result of cross product of two 3D vectors. For detailed info https://en.wikipedia.org/wiki/Cross_product
t_vec3		vec3_cross(t_vec3 vec1, t_vec3 vec2);

//3D versions of dot product. For detailed info https://en.wikipedia.org/wiki/Dot_product
double		vec3_dot(t_vec3 vec1, t_vec3 vec2);
//3D verison of distance function.
double		get_dist3(t_vec3 point1, t_vec3 point);
//3D version of magnitude function. This function gives lenght of 3D vectors.
double		vec3_mag(t_vec3 vec);

//This function normalizes 4D vectors. For detailed info https://en.wikipedia.org/wiki/Unit_vector
t_vec4		vec4_norm(t_vec4 vec);

//4D versions of dot product. For detailed info https://en.wikipedia.org/wiki/Dot_product
double		vec4_dot(t_vec4 vec1, t_vec4 vec2);
//4D version of magnitude function. This function gives lenght of 4D vectors.
double		vec4_mag(t_vec4 vec);

//------------------------- Transformation Matrices --------------------------

//This function translate any 3D vector to given values.
t_vec3		mtx3_trans(double x, double y, double z, t_vec3 vec);
//This function scale any 3D vector to given values.
t_vec3		mtx3_scale(double x, double y, double z, t_vec3 vec);
//This function rotate any 3D vector to given values.
t_vec3		mtx3_rot(double x, double y, double z, t_vec3 vec);

//----------------------- Render Pipeline ------------------------------------

//This function creates transformation matrix. t = Translation, r = Rotation, s = Scale
t_mtx4		transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s);

//This function is part of the Transformation pipeline. Used for local space transformations.
t_vec4		loc_trans(t_mtx4 mtx, t_vec3 vec);
//This function is part of the Transformation pipeline. Used for global space transformations.
t_vec4		glob_trans(t_mtx4 mtx_glob, t_mtx4 mtx_loc, t_vec3 vec);
//Transformation from Global Space to Clip Space. proj = Selected projection matrix.
t_vec3		glob_to_clip(t_mtx4 proj, t_mtx4 mtx_glob, t_mtx4 mtx_loc, t_vec3 vec);
t_vec3		clip_to_screen(t_vec3 vec);
t_vec3		transform_pipeline(t_mtx4 proj, t_mtx4 mtx_glob, t_mtx4 mtx_loc, t_vec3 vec);
t_vec3		*get_screen_points(t_data *d, int i, int j, int curr);

void		set_row3(t_mtx3 *mtx, int row_val, t_vec3 row);
t_vec3		get_row3(t_mtx3 mtx, int row_val);
t_vec3		mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
t_mtx3		mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);

void		set_row4(t_mtx4 *mtx, int row_val, t_vec4 row);
t_vec4		get_row4(t_mtx4 mtx, int row_val);
t_vec4		mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
t_mtx4		mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);

t_vec4		vec3_to_vec4(t_vec3 vec3, double w);
t_vec3		vec4_to_vec3(t_vec4 vec4);

t_color		set_color(__uint8_t a, __uint8_t r, __uint8_t g, __uint8_t b);
t_color		get_gradient_val(t_color from, t_color to, double value);
t_gradient	set_gradient(t_color from, t_color to);
t_gradient	inv_gradient(t_gradient in);

void		put_pixel(t_img *img, int x, int y, t_color color);
void		draw_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_color color);
void		gradient_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient grad);
void		draw_tri(t_data *data, t_tri *tris, int j, t_color color);
void		draw_map(t_data *d, t_vec3 *tr_map);
int			draw_image(t_data *data);
void		fill_img(t_data *data, t_color color);

int			input(int keycode, t_data *data);
int			update(t_data *data);

void		free_str_arr(char **str_arr);
int			data_counter(int obj_file, char type);
int			get_vertex_data(t_get_vert *ver);
t_vec3		*get_vertices(char *obj_path, int *ver_count);
int			get_triangle_data(t_get_tris *tris, t_vec3 *vertices);
t_tri		*get_triangles(char *obj_path, t_vec3 *vertices, int *tri_count);
t_mesh		mesh_init(char *obj_path);

int			fdf_map_get_pos_data(t_fdf_data *d, t_fdf_map *map);
t_fdf_map	*fdf_map_init(char *fdf_path);
int			draw_fdf(t_data *data);

t_mtx4		orto_init(void);
t_mtx4		pers_init(void);

#endif
