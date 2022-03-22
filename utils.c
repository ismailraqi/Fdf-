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
double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_pixel current, t_pixel start, t_pixel end, t_cord delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}