#ifndef STRUCT_H
#define STRUCT_H

typedef struct 	s_pixel
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				count;
	struct s_pixel	*next;
}				t_pixel;

typedef struct	s_cord
{
	int	x;
	int	y;
	int	num;
}				t_cord;

typedef	struct s_data
{
	t_pixel	*curr_pixel;
	char	*line;
	int		fd;
	int		w_count;
	int		l_count;
	int		win_x;
	int		win_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;


#endif 