/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/09 20:47:36 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include "fdf_structs.h"
# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"

//Special include to work on multi platform.
# ifdef __linux__
#  include <X11/keysym.h>
#  define ESC_KEY XK_Escape
#  define W_KEY XK_w
#  define A_KEY XK_a
#  define S_KEY XK_s
#  define D_KEY XK_d
#  define F_KEY XK_f
#  define G_KEY XK_g
#  define X_KEY XK_x
#  define Z_KEY XK_z
#  define E_KEY XK_e
#  define Q_KEY XK_q
#  define R_KEY XK_r
#  define T_KEY XK_t
#  define O_KEY XK_o
#  define P_KEY XK_p
# else
#  define ESC_KEY 53
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define F_KEY 3
#  define G_KEY 5
#  define X_KEY 7
#  define Z_KEY 6
#  define E_KEY 14
#  define Q_KEY 12
#  define R_KEY 15
#  define T_KEY 17
#  define O_KEY 31
#  define P_KEY 35
# endif

//Window Aspects
# define WIDTH		1000.
# define HEIGHT		1000.
//Ortographic Camera Options
# define O_TOP			10.
# define O_BOT			-10.
# define O_RIGHT		10.
# define O_LEFT			-10.
# define O_NEAR 		1.
# define O_FAR 			100.
//Perspective Camera Options
# define P_NEAR_CLIP	1.
# define P_FAR_CLIP		100.
# define P_FOV			70.
# define P_ASPECT_R		HEIGHT / WIDTH
//Error codes
# define INVALID_FORMAT	0
# define LOAD_ERROR		1
# define MLX_ERROR		2

//----------------------- Error And Input Handling ---------------------

//Initialization function for main process.
void		main_init(t_fdf *fdf, char *obj_path);
//Function for displaying error messages.
int			error_msg(int error_code);
//Terminating program without leak.
int			terminate_prog(t_fdf *fdf, int exit_state);
//Null-Checker with easy exit.
void		null_checker(t_fdf *fdf, void *value, int error_code);
//Input manager function.
int			input(int keycode, t_fdf *fdf);
//Function for real-time render.
int			update(t_fdf *fdf);

/*Gets numbers of strings inside of string arrays.
String arrays must be null-ended.*/
size_t		ft_strarrlen(char **arr);
//Free all the arrays inside double array.
void		free_str_arr(char **str_arr);
/*Hexadecimal version of atoi().
It works both of uppercase and lowercase versions.*/
int			ft_atoi_hex(const char *str);
//Degree to Radian conversions.
double		deg_to_rad(double deg);
//Radian to Degree conversions.
double		rad_to_deg(double rad);

//----------------------------- Mapping ----------------------------------

//Initializes map from given values to use inside map function.
t_map		map_init(double min_i, double max_i, double min_o, double max_o);
/*Gives normalized value (0 to 1 range value)
of given value inside specified range.*/
double		normalize(double val, double min, double max);
/*Gets normalized value (0 to 1 range value)
and gives the value corresponding on specified range.*/
double		lerp(double val, double min, double max);
//This function uses t_map to convert value from one range to another.
double		map(double val, t_map map);

//----------------------- Basic Graphics Pipeline --------------------------

/*This function creates transformation matrix.
t = Translation, r = Rotation, s = Scale*/
t_mtx4		transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s);
/*Starting point of pipeline.
For detailed info https://en.wikipedia.org/wiki/Graphics_pipeline */
t_vec3		graphic_pipeline(t_mtx4 proj, t_mtx4 mtx_glob,
				t_mtx4 mtx_loc, t_vec3 vec);
/*This function uses defined pipeline to generate
3D graphics to display 2D screen.
Iterate throught all the points and apply pipeline.*/
t_vec3		*renderer(t_fdf *d, int i, int j, int curr);

//------------------------------ Basic Matrix Functions ---------------------

//3D matrix row setter.
void		set_row3(t_mtx3 *mtx, int row_val, t_vec3 row);
//Get values in row of 3D matrix.
t_vec3		get_row3(t_mtx3 mtx, int row_val);
//3D matrix 3D vector multiplication.
t_vec3		mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec);
//3D matrix 3D matrix multiplication.
t_mtx3		mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2);

//4D matrix row setter.
void		set_row4(t_mtx4 *mtx, int row_val, t_vec4 row);
//Get values in row of 4D matrix.
t_vec4		get_row4(t_mtx4 mtx, int row_val);
//4D matrix 4D vector multiplication.
t_vec4		mtx_vec_mul4(t_mtx4 mtx, t_vec4 vec);
//4D matrix 4D matrix multiplication.
t_mtx4		mtx_mtx_mul4(t_mtx4 mtx1, t_mtx4 mtx2);

//3D vector to 4D vector conversion.
t_vec4		vec3_to_vec4(t_vec3 vec3, double w);
//4D vector to 3D vector conversion.
t_vec3		vec4_to_vec3(t_vec4 vec4);

//---------------------------- Draw Functions --------------------------
void		gradient_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient grad);
void		draw_map(t_fdf *d, t_vec3 *tr_map);
int			draw_image(t_fdf *fdf);

//------------------------------- FDF Map Functions ---------------------

int			fdf_get_size(t_fdf_data *d, t_fdf_map *map);
int			fdf_map_init_color(t_fdf_data *d, t_fdf_map *map, char *path);
t_fdf_map	*fdf_map_init(char *fdf_path);
int			fdf_map_init_pos_data(t_fdf_data *d, t_fdf_map *map, char *path);

#endif
