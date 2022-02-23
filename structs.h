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

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_map			*map;
	t_pixel			**lines_map;

	int				zoom;
}					t_data;

typedef struct 		s_lines
{
	t_pixel			*line;
	struct	s_lines	*next;
}					t_lines;

typedef struct 		s_draw
{
	t_cord			delta;
	t_cord			sign;
	t_cord			current;
	int				d;
	double			r;	
}					t_draw;


#endif 