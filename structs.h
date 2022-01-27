#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_pixel
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_pixel	*next;
	
}	t_pixel;

typedef	struct s_data
{
	t_pixel	pixel;
	int		win_x;
	int		win_y;
	int		w_count;
	int		l_count;
	int		**map;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;


#endif 