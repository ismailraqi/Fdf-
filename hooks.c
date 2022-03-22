#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
		exit(0);
    }
	if (keycode == C_KEY)
		mlx_clear_window(data->mlx,data->win);	
	printf("Hello from key_hook! pressed button is ====> %d\n",keycode);
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{    
    printf("Hello from mouse_hook!  ====> %d\t%d\n",x,y);
    return (1);
}