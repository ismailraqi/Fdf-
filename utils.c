#include "fdf.h"


static	int	contains(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int	get_hight_n_color(t_pixel *pixel, char *str, int size, char *base)
{
	int	i;
	int	t;

	if (!str)
		return (-1);
	i = 0;
	t = -1 * (str[i] == '-') + (str[i] == '+');
	i += (t != 0);
	t += (t == 0);
	while (str[i] >= '0' && str[i] <= '9')
		pixel->z = (i++, 10 * pixel->z + (str[i - 1] - '0'));
	pixel->z *= t;
	if (i == size)
		return (0);
	i += 3;
	while (i < size)
	{
		t = (str[i] == 'A') * 10 + (str[i] == 'B') * 11 + (str[i] == 'C') * 12;
		t = (str[i] == 'D') * 13 + (str[i] == 'E') * 14 + (str[i] == 'F') * 15;
		if (!t)
			t = contains(base, str[i]);
		if (t < 0)
			return (0);
		pixel->color = (i++, (pixel->color << 4) | t);
	}
	return (0);
}

void	map_filler(t_pixel **pixels, t_map *map)
{
	t_pixel *curr;
	int		i;

	curr = *pixels;
	map->map_cordinates = (int *) malloc((map->map_size)*(sizeof(int)));
	if (!map->map_cordinates)
		exit(EXIT_FAILURE);
	map->map_colors = (int *) malloc((map->map_size)*(sizeof(int)));
	if (!map->map_colors)
		exit(EXIT_FAILURE);
	i = 0;
	while (curr)
	{
		map->map_cordinates[i] = curr->z;
		map->map_colors[i] 	   = curr->color;
		curr = curr->next;
		i++;
	}
}

int		get_index(int x, int y, int map_size)
{
	return (y * map_size + x);
}

t_cord	new_point(int x, int y, t_map *map)
{
	t_cord	point;
	int		index;

	index = get_index(x, y, map->map_size);
	point.x = x;
	point.y = y;
	point.z = map->map_cordinates[index];
	point.color = map->map_colors[index];
	return (point);
}

// int	ft_abs(int x)
// {
// 	if (x > 0)
// 		return ((x*(-1)));
// 	return (x);
// }