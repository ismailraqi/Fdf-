/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:08:06 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/20 01:13:01 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	*getlast(t_pixel *h)
{
	while (h->next)
		h = h->next;
	return (h);
}

static	t_split	*init_param(void)
{
	t_split	*param;

	param = (t_split *) malloc(sizeof(t_split));
	if (!param)
		return (NULL);
	param->beg = 0;
	param->end = 0;
	param->new = NULL;
	return (param);
}

static	void	*find_position(char *str, t_split *param)
{
	while (str[param->end] == ' ')
		param->end = (param->beg++, param->end + 1);
	while (str[param->end] && str[param->end] != ' ')
		param->end++;
	return (param);
}

t_pixel	*split_delim(char *str, t_cord *cord, t_pixel **last)
{
	t_split	*param;

	param = init_param();
	if (!str)
		return (NULL);
	while (str[param->end])
	{
		find_position(str, param);
		*last = add_pixel(&param->new, str + param->beg, \
		cord, param->end - param->beg);
		if ((param->end > param->beg) && !*last)
			return (pixels_clear(&param->new), NULL);
		param->beg = param->end;
	}
	param->tmp = param->new;
	param->new = (t_pixel *)malloc(cord->x * sizeof(t_pixel));
	if (!param->new)
		return (pixels_clear(&param->tmp), NULL);
	param->beg = 0;
	while (param->beg < cord->x)
	{
		param->new[param->beg++] = *(param->tmp);
		param->tmp = param->tmp->next;
	}
	return (param->new);
}
