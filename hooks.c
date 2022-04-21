/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:20:52 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/21 00:23:21 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == I_KEY)
		data->is_parallel = 1;
	if (keycode == P_KEY)
		data->is_parallel = 0;
	if (keycode == UP_KEY)
		data->cam->y_pos -= 10;
	if (keycode == DOWN_KEY)
		data->cam->y_pos += 10;
	if (keycode == LEFT_KEY)
		data->cam->x_pos -= 10;
	if (keycode == RIGHT_KEY)
		data->cam->x_pos += 10;
	mlx_clear_window(data->mlx, data->win);
	draw(data->lines_map, data);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;
	t_cam	*cam;

	data = (t_data *)param;
	cam = data->cam;
	if (button == 5)
	{
		cam->zoom += 0.2;
		mlx_clear_window(data->mlx, data->win);
		draw(data->lines_map, data);
	}
	if (button == 4)
	{
		if (cam->zoom > 0.3)
		{
			cam->zoom -= 0.2;
			mlx_clear_window(data->mlx, data->win);
			draw(data->lines_map, data);
		}
	}
	return (1);
}
