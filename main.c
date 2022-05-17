/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/17 21:43:20 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	ext_checker(char *ext, char *base)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (ext[i] != base[i])
			return (0);
	return (1);
}

static	int	file_checker(char *fname)
{
	int	fd;
	int	fname_len;
	int	ext_pos;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (0);
	fname_len = ft_strlen(fname);
	ext_pos = fname_len - 4;
	if (!ext_checker(fname + ext_pos, ".fdf"))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_pixel		*last;
	t_get_list	*list;

	last = NULL;
	if (ac != 2 || !file_checker(av[1]))
		(put_str("Invalid file or file does not have permission"), \
			put_str("USAGE ./fdf {filename}.fdf"), \
			exit(EXIT_FAILURE));
	data = mlx_initializer();
	list = get_list(av[1], &last);
	if (!list->lines || last->count <= 0)
		(put_str("Invalid MAP"), exit(EXIT_FAILURE));
	data->map = map_initializer(last);
	data->cam = cam_initializer(data);
	data->lines_map = lines_to_map(list->lines, data->map->height + 1);
	draw(data->lines_map, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
