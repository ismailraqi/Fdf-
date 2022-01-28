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


static	void	read_map(t_data *data, char *f_name)
{
	char	*line;
	int		fd;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	data->map = (t_map *) malloc(sizeof(t_map));
	if (!data->map)
		exit(EXIT_FAILURE);
	data->map->w_count = w_counter(line, ' ');
	data->map->l_count = 0;
	close(fd);
}

static void p_pixel(t_pixel *pxl)
{
	t_pixel *tmp;

	tmp = pxl;
	while (tmp)
	{
		printf("%d\t %d \n",tmp->z, tmp->color);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_pixel *pixel_lst;

	if (ac != 2)
		exit(EXIT_FAILURE);
	pixel_lst = NULL;
	read_map(&data, av[1]);
	init_map(&data, av[1], &pixel_lst);
	p_pixel(pixel_lst);
	die("Done\n",EXIT_SUCCESS,&pixel_lst);
	return (0);
	
}


