/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:14:41 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/25 00:39:37 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_get_list	*init_param(char *fname)
{
	t_get_list	*param;

	param = (t_get_list *) malloc(sizeof(t_get_list));
	param->fd = open(fname, O_RDONLY);
	if (param->fd < 0)
		return (NULL);
	param->line = (char *)malloc(10000);
	if (!param->line)
		return (NULL);
	param->cord.num = 0;
	param->cord.y = 0;
	param->lines = NULL;
	return (param);
}

t_lines	*get_list(char *fname, t_pixel **last)
{
	int			bytes;
	t_get_list	*p;

	p = init_param(fname);
	while (1)
	{
		bytes = 0;
		p->cord.x = 0;
		while (read(p->fd, p->line + bytes, 1) == 1 && p->line[bytes] != '\n')
			++bytes;
		if (!bytes)
			return (close(p->fd), free(p->line), p->lines);
		p->line[bytes + (p->line[bytes] == '\n')] = '\0';
		p->tmp = split_delim(p->line, &p->cord, last);
		cat_lines(&p->lines, new_line(p->tmp));
		p->cord.y++;
	}
	free(p);
}
