#include "fdf.h"

static void	fill_map(int	*data, char *line)
{
	char    **cordinate;
	int		i;
	
	i = 0;
	cordinate = ft_split(line,' ');
	
	while (cordinate[i])
	{
		data[i] = ft_atoi(cordinate[i]);
		free(cordinate[i]);
		i++;
	}
	free(cordinate);
}

void    init_map(t_data *data, char *f_name)
{
	int     i;
	int		fd;
	char    *line;

	fd = open(f_name, O_RDONLY);
	data->map = (int**) malloc(sizeof(int *) * (data->l_count + 1));
	i = -1;
	while (++i <= data->l_count)
		data->map[i] = (int *) malloc(sizeof(int) * (data->w_count + 1));
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		fill_map(data->map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
}

