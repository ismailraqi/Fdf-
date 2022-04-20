#ifndef STRUCT_H
#define STRUCT_H

typedef struct 		s_pixel
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				count;
	struct s_pixel	*next;
}					t_pixel;

typedef struct		s_cord
{
	int				x;
	int				y;
	int				num;
}					t_cord;

typedef struct		s_map
{
	int				map_size;
	int				height;
	int				width;
}					t_map;

typedef	struct 		s_camera
{
	double			zoom;
	int				x_pos;
	int				y_pos;
}					t_cam;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	int				is_zoom;
	int				x_mouse;
	int				y_mouse;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				is_parallel;
	t_map			*map;
	t_pixel			**lines_map;
	t_cam			*cam;
}					t_data;

typedef	struct 		s_split_param
{
	t_pixel	*new;
	t_pixel	*tmp;
	int		beg;
	int		end;
}					t_split;

typedef struct 		s_lines
{
	t_pixel			*line;
	struct	s_lines	*next;
}					t_lines;

typedef	struct 		s_get_list_param
{
	t_cord	cord;
	t_lines	*lines;
	t_pixel	*tmp;
	char	*line;
	int		fd;
	int		bytes;
}					t_get_list;

typedef struct 		s_draw
{
	t_cord			delta;
	t_cord			sign;
	t_pixel			current;
	int				error[2];
}					t_draw;

#endif 