# include "fdf.h"

t_map   *map_initializer(t_pixel *last)
{
    t_map   *map;

    map = (t_map *) malloc(sizeof(t_map));
    if (!map)
        exit(EXIT_FAILURE);
    map->map_size = last->count;
    map->height = last->y+1;
    map->width = ((last->count+1) / (last->y+1));
    return (map);
}

t_data  *mlx_initializer()
{
    t_data *data;

    data = (t_data *) malloc(sizeof(t_data));
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line, &data->endian);
    return (data);
}

t_cam   *cam_initializer(t_data *data)
{
    t_cam   *cam;

    cam = (t_cam *) malloc(sizeof(t_cam));
    cam->x_pos = (WIDTH / 2);
    cam->y_pos = (HEIGHT / 2);
    if (data->map->width > 500)
        cam->zoom = 5;
    else if (data->map->width > 300)
        cam->zoom = 7;
    else 
        cam->zoom = 20;
    cam->z = 1;
    return (cam);
}