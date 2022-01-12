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


int	main(int ac, char **av)
{
	int				fd;
	int				w_count;
	int				l_count;
	char			*line;
	
	
	if (ac > 2)
		ft_putstr("Too many arguments");
	else if (ac <= 1)
		ft_putstr("At least one argument !");
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	l_count = 0;
	w_count = w_counter(line, ' ');
	while (line != NULL)
	{
		printf("%s\n",line);
		free(line);
		line = get_next_line(fd);
		l_count++;
	}
	printf("%d\t%d", w_count, l_count);
	return 0;
}