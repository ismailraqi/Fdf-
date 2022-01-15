#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	key_hook(int keycode, t_data *ptr)
{
	printf("%s", "hello");
	return 0;
}
int	main(void)
{
	t_data	img;
	t_vars	vars;
	int i = 0;
	int x = 1920;
	int y = 1080;
	int j = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920,1080,"test");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	mlx_string_put(vars.mlx,vars.win,600,600,0x00FF0000,"hello");

	while(i < 100)
	{
		while(j < x)
		{
			my_mlx_pixel_put(&img, j,i,0x00FF0000);
			j++;
		}
		j = 0;
		i++;
	}
	j = 0;
	i = 980;
	while(i < y)
	{
		while(j < x)
		{
			my_mlx_pixel_put(&img, j,i,0x00FF0000);
			j++;
		}
		j = 0;
		i++;
	}
	j = 0;
	i = 0;
	while(j < 100)
	{
		while(i < y)
		{
			my_mlx_pixel_put(&img, j,i,0x00FF0000);
			i++;
		}
		i = 0;
		j++;
	}
	j = 1820;
	i = 0;
	while(j < x)
	{
		while(i < y)
		{
			my_mlx_pixel_put(&img, j,i,0x00FF0000);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(vars.mlx,vars.win,img.img,0,0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
