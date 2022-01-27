/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/01/12 02:45:52 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	w_counter(char *src, char delimiter)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	if (!src)
		return (wc);
	if (src[i] != delimiter)
		wc++;
	while (src[i] != '\0')
	{
		if (src[i] != delimiter && src[i - 1] == delimiter)
			wc++;
		i++;
	}
	return (wc);
}

static	int	l_counter(int fd)
{
	char	*line;
	int		l_count;

	line = get_next_line(fd);
	l_count = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		l_count++;
	}
	return (l_count);
}

static	void	read_map(char	*f_name, t_data *data, int	*fd)
{
	*fd = open(f_name, O_RDONLY);
	if (*fd == -1)
		return ;
	data->w_count = w_counter(get_next_line(*fd), ' ');
	data->l_count = l_counter(*fd);
	close(*fd);
}

int	main(int ac, char **av)
{
	int		fd;

	t_data	data;
	if (ac != 2)
		exit(-1);
	read_map(av[1], &data, &fd);
	init_map(&data,av[1]);

	return (0);
}


