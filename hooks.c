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
	draw(data->lines_map,data);
	//printf("Hello from key_hook! pressed button is ====> %d \t%f\twidth : %d\theight : %d\n", keycode,data->cam->zoom,data->map->width, data->map->height);
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data = (t_data *)param;

	t_cam	*cam = data->cam;
	if (button == 5)
	{
		cam->zoom += 0.2;
		mlx_clear_window(data->mlx, data->win);
		draw(data->lines_map,data);
	}
	if (button == 4)
	{
		if (cam->zoom > 0.3)
		{
			cam->zoom -= 0.2;
			mlx_clear_window(data->mlx, data->win);
			draw(data->lines_map,data);
		}
	}
    printf("Hello from mouse_hook!  ====> %f\n",data->cam->zoom);
    return (1);
}