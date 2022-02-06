#include "fdf.h"

// int	key_hook(int keycode, t_data *data)
// {
// 	if (keycode == ESC_KEY)
// 		exit(0);
// 	if (keycode == C_KEY)
// 		mlx_clear_window(data->instance,data->window_instance);	
// 	printf("Hello from key_hook! pressed button is ====> %d\n",keycode);
// 	return (0);
// }

int mouse_hook(int button, int x, int y, void *param)
{    
    printf("Hello from mouse_hook!  ====> %d\t%d\n",x,y);
    return (1);
}