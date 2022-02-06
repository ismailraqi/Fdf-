#include "fdf.h"

t_pixel	*get_list(char *fname,t_pixel **last)
{
	t_cord	cord;
	t_pixel	*pixels;

	char	*line;
	int		fd;
	int		bytes;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = (char *)malloc(10000);
	if (!line)
		return (NULL);
	pixels = NULL;
	cord.num = 0;
	cord.y = 0;
	while (1)
	{
		bytes = 0;
		cord.x = 0;
		while (read(fd, line + bytes, 1) == 1 && line[bytes] != '\n' && ++bytes);
		if (!bytes)
			return (close(fd), free(line), pixels);
		line[bytes + (line[bytes] == '\n')] = '\0';
		(cat_lst(&pixels, split_delim(line, ' ', &cord, last)), cord.y++);
	}
}
