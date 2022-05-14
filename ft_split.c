/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:08:06 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/14 00:25:52 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_split	*init_param(void)
{
	t_split	*param;

	param = (t_split *) malloc(sizeof(t_split));
	printf("Address split param %p\n", param);
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
	printf("Address split param new %p\n", param->new);
	if (!param->new)
		return (pixels_clear(&param->new), free(param), NULL);
	param->beg = 0;
	while (param->beg < cord->x)
	{
		param->new[param->beg++] = *(param->tmp);
		if (param->tmp->x == 0)
			free(param->tmp);
		printf("the one: %p -- %d %d\n", param->tmp, param->tmp->x, param->tmp->y);
		param->tmp = param->tmp->next;
	}
	tmp = param->new;
	free(param);
	return (tmp);
}
