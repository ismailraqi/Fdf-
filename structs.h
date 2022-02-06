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
	int				zoom;
}					t_data;

#endif 