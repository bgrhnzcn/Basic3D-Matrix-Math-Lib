/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/03 22:33:37 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <math.h>

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

typedef struct s_mtx3
{
	t_vec3	i;
	t_vec3	j;
	t_vec3	k;
}	t_mtx3;



float	deg_to_rad(float deg);
t_vec3	mul(t_mtx3 matrix, t_vec3 vec3);
#endif
