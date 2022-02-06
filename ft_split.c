#include "fdf.h"

t_pixel	*getlast(t_pixel *h)
{
	while (h->next)
		h = h->next;
	return (h);
}

t_pixel	*split_delim(char *str, t_cord *cord, t_pixel **last)
{
	t_pixel	*new;
	t_pixel	*tmp;
	int		beg;
	int		end;

	if (!str)
		return (NULL);
	beg = 0;
	end = 0;
	new = NULL;
	while (str[end])
	{
		while (str[end] == ' ')
			end = (beg++, end + 1);
		while (str[end] && str[end] != ' ')
			end++;
		*last = add_pixel(&new, str + beg, cord, end - beg);
		if ((end > beg) && !*last)
			return (pixels_clear(&new), NULL);
		beg = end;
	}
	tmp = new;
	new = (t_pixel *)malloc(cord->x * sizeof(t_pixel));
	if (!new)
		return (pixels_clear(&tmp), NULL);
	beg = 0;
	while (beg < cord->x)
	{
		new[beg++] = *(tmp);
		tmp = tmp->next;
	}
	return (new);
}