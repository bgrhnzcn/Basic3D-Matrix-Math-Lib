/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:40:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/07 15:44:53 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*obj_path;

	if (argc != 2)
		return (0);
	obj_path = argv[1];
	if (!ft_strnstr(obj_path, ".fdf", ft_strlen(obj_path)))
		return (error_msg(INVALID_FORMAT), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	main_init(data, obj_path);
	ft_printf("Running...");
	data->time = 0;
	mlx_hook(data->win, 17, 0, terminate_prog, data);
	mlx_hook(data->win, 2, 1, input, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop(data->mlx);
	return (0);
}
