/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:40:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 21:36:20 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*obj_path;

	if (argc != 2)
		return (0);
	obj_path = argv[1];
	if (!ft_strnstr(obj_path, ".fdf", ft_strlen(obj_path)))
		return (error_msg(INVALID_FORMAT), EXIT_FAILURE);
	fdf = ft_calloc(1, sizeof(t_fdf));
	main_init(fdf, obj_path);
	ft_printf("Running...");
	fdf->data.time = 0;
	mlx_hook(fdf->data.win.win, 17, 0, terminate_prog, &fdf->data);
	mlx_hook(fdf->data.win.win, 2, 1, input, &fdf->data);
	mlx_loop_hook(fdf->data.mlx, update, &fdf->data);
	system("MallocStackLogging=1 leaks fdf");
	mlx_loop(fdf->data.mlx);
	return (0);
}
