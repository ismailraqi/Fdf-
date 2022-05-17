/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:33:47 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/15 16:38:29 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	*add_pixel(t_pixel **head, char *str, t_cord *cord)
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
	if (get_hight(new, str))
		return (free(new), NULL);
	new->count = cord->num++;
	if (!*head)
		return (*head = new, new);
	curr = *head;
	while (curr->next)
		curr = curr->next;
	return (curr->next = new, new);
}

void	pixels_clear(t_pixel **head)
{
	t_pixel	*current;
	t_pixel	*next;

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
