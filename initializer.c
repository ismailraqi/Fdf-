# include "fdf.h"

t_map   *map_initializer(t_pixel *head)
{
    t_map   *map;

    map = (t_map *) malloc(sizeof(t_map));
    if (!map)
        exit(EXIT_FAILURE);
    map->map_size = head->count;
    map->height = head->y;
    map->width = ((head->count+1) / (head->y+1));
    return (map);
}

t_data  *mlx_initializer(void)
{
    t_data *data;

    data = (t_data *) malloc(sizeof(t_data));
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1000, 1000, "FDF");
    data->img = mlx_new_image(data->mlx, 1000, 1000);
    data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line, &data->endian);
    data->zoom = 20;
    return (data);
}