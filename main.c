/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:12 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/01 00:42:07 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <X11/keysym.h>

typedef struct s_mng{
	void	*mlx;
	void	*win;
}	t_mng;

typedef struct s_pos{
	t_mng	*mng;
	int		x;
	int		y;
}	t_pos;

int	get_pos(t_pos *mouse)
{
	mlx_mouse_get_pos(mouse->mng->mlx, mouse->mng->win, &mouse->x, &mouse->y);
	printf("posx: %d, posy: %d\n", mouse->x, mouse->y);
	sleep(1);
}

int	main(void)
{
	t_mng	mng;
	t_img	*img;
	t_pos	mouse;
	int		width;
	int		height;

	mng.mlx = mlx_init();
	width = 800;
	height = 600;
	mng.win = mlx_new_window(mng.mlx, width, height, "Test");
	img = mlx_new_image(mng.mlx, 200, 300);
	mouse.mng = &mng;
	mouse.x = 0;
	mouse.y = 0;
	mlx_put_image_to_window(mng.mlx, mng.win, img, width, height);
	mlx_loop_hook(mng.mlx, get_pos, &mouse);
	mlx_loop(mng.mlx);
	
}
