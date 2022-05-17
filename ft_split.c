/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:08:06 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/15 17:26:52 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static	t_split	*find_position(char *str, t_split *param)
{
	while (str[param->end] == ' ')
		param->end = (param->beg++, param->end + 1);
	while (str[param->end] && str[param->end] != ' ')
		param->end++;
	return (param);
}

static	void	pixels_filler(t_split *param, t_cord *cord)
{
	while (param->beg < cord->x)
	{
		param->new[param->beg++] = *(param->tmp);
		if (param->tmp->x == 0)
			free(param->tmp);
		param->tmp = param->tmp->next;
	}
}

t_pixel	*split_delim(char *str, t_cord *cord, t_pixel **last)
{
	t_split	*param;
	t_pixel	*tmp;

	param = init_param();
	if (!str)
		return (NULL);
	while (str[param->end])
	{
		find_position(str, param);
		*last = add_pixel(&param->new, str + param->beg, cord);
		if ((param->end > param->beg) && !*last)
			return (pixels_clear(&param->new), free(param), NULL);
		param->beg = param->end;
	}
	param->tmp = param->new;
	param->new = (t_pixel *)malloc(cord->x * sizeof(t_pixel));
	if (!param->new)
		return (pixels_clear(&param->new), free(param), NULL);
	param->beg = 0;
	pixels_filler(param, cord);
	tmp = param->new;
	free(param);
	return (tmp);
}
