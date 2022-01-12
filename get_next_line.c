/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:35 by iraqi             #+#    #+#             */
/*   Updated: 2021/12/09 22:02:21 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joiner(char *str, int bytes)
{
	char	*tmp;

	tmp = (char *)malloc((bytes + BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, str, bytes);
	free(str);
	return (tmp);
}

int	ft_get_line(t_args *args, char *c, int fd)
{
	args->j = 0;
	while ((args->j < BUFFER_SIZE) && *c != '\n')
	{
		args->r = read(fd, c, 1);
		if (args->r == 0)
		{
			args->str = ft_checker(args);
			if (args->str == NULL)
				return (-1);
			return (1);
		}
		if (args->r == -1)
		{	
			free(args->str);
			args->str = NULL;
			return (-1);
		}
		(args->str)[args->bytes + args->j++] = *c;
	}
	return (0);
}

int	ft_cleaner(t_args *args, char *c)
{
	if (*c == '\n')
	{
		args->tmp = ft_strdup(args->str);
		*c = 0;
		free(args->str);
		args->str = args->tmp;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	c;
	t_args		args;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	args.str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!args.str)
		return (NULL);
	args.bytes = 0;
	while (1)
	{
		if (ft_get_line(&args, &c, fd) != 0)
			return (args.str);
		(args.str)[args.bytes + args.j] = '\0';
		if (ft_cleaner(&args, &c) != 0)
			return (args.str);
		args.bytes += args.j;
		args.str = ft_joiner(args.str, args.bytes);
		if (!args.str)
			return (NULL);
	}
	args.str[args.j] = '\0';
	return (args.str);
}
