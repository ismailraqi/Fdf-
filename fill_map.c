#include "fdf.h"

static int	ft_free(char **res, int row)
{
	if (res[row] == NULL)
	{
		while (--row >= 0)
			free(res[row]);
		free(res);
		return (1);
	}
	return (0);
}

static void	fill_map(t_pixel **pixel_lst, char *line, int line_index)
{
	char    **cordinate;
	char 	*color;
	int		i;
	
	i = 0;
	cordinate = ft_split(line,' ');
	//check for color
	while (cordinate[i])
	{
		color = ft_strchr(cordinate[i],',');
		if(add_pixel(pixel_lst, new_pixel(i, line_index, ft_atoi(cordinate[i]),s_hextoi(color))))
		{
			ft_free(cordinate,i);
			die("Pixel can't be added to the list\n",EXIT_FAILURE,pixel_lst);
		}
		i++;
	}
}

void    init_map(t_data *data, char *f_name, t_pixel **pixel_lst)
{
	int		fd;
	char    *line;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	while (line != NULL)
	{
		fill_map(pixel_lst, line, data->map->l_count);
		free(line);
		line = get_next_line(fd);
		data->map->l_count++;
	}
	close(fd);
}
