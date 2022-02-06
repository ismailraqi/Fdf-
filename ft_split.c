#include "fdf.h"

t_pixel	*split_delim(char *str, char d, t_cord *cord, t_pixel **last)
{
	t_pixel	*new;
	int		beg;
	int		end;

	if (!str)
		return (NULL);
	beg = 0;
	end = 0;
	new = NULL;
	while (str[end])
	{
		while (str[end] == d)
			end = (beg++, end + 1);
		while (str[end] && str[end] != d)
			end++;
		*last = add_pixel(&new, str + beg, cord, end - beg);
		if ((end > beg) && !*last)
			return (pixels_clear(&new), NULL);
		beg = end;
	}
	return (new);
}