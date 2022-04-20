#include "fdf.h"

int max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int sign_test(int a, int b)
{
    if (a < b)
        return (1);
    return (-1);
}

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
