#include "fdf.h"

t_pixel *new_pixel(int x,int y, int z, int color)
{
	t_pixel *new_p;

	new_p = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new_p)
		return (NULL);
	new_p->x = x;
	new_p->y = y;
	new_p->z = z;
	new_p->color = color;
	new_p->next = NULL;
	return (new_p);
}

t_pixel	*add_pixel(t_pixel **head, char *str, t_cord *cord, int size)
{
	t_pixel	*new;
	t_pixel	*curr;

	new = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new)
		return (NULL);
	new->z = 0;
	new->color = 0x00ffffff;
	new->x = cord->x++;
	new->y = cord->y;
	new->next = NULL;
	if (get_hight_n_color(new, str, size, "01234567890abcdef"))
		return (free(new), NULL);
	new->count = cord->num++;
	if (!*head)
		return (*head = new, new);
	curr = *head;
	while (curr->next)
		curr = curr->next;
	return (curr->next = new, new);
}

void    pixels_clear(t_pixel **head)
{
    t_pixel	*current;
	t_pixel *next;

    current = *head;

    while (current)
    {		
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void	cat_lst(t_pixel **mother, t_pixel *son)
{
	t_pixel	*curr;

	if (*mother)
	{
		curr = *mother;
		while (curr->next)
			curr = curr->next;
		curr->next = son;
	}
	else
		*mother = son;
}


void    die(char *msg, int code, t_pixel **lst)
{
    if (lst)
        pixels_clear(lst);
    if (msg)
        write(2, msg, ft_strlen(msg));
    exit(code);
}
