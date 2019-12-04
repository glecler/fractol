#include "fractol.h"

void	ft_zoom(t_win_data *win_data)
{
	win_data->im_min /= 1.2;
	win_data->re_min /= 1.2;
	win_data->step = (win_data->im_max - win_data->im_min) / 600.0;
	printf("%Lf \n", win_data->step);
	win_data->re_max = (-1) * win_data->re_min;
	win_data->im_max = (-1) * win_data->im_min;
}

void		ft_unzoom(t_win_data *win_data)
{
	win_data->im_min *= 1.2;
	win_data->re_min *= 1.2;
	win_data->im_max = (-1) * win_data->im_min;
	win_data->re_max = (-1) * win_data->re_min;
	win_data->step = (win_data->im_max - win_data->im_min) / 600.0000000;
}

int		get_key(int key, void *param)
{
	t_win_data *win_data;
	int res;

	win_data = param;
	printf("key %d\n", key);
	if (key == 126)
		ft_zoom(win_data);
	if (key == 125)
		ft_unzoom(win_data);
	if (key == 123)
		win_data->var.julia_c.re += .1;
	if (key == 124)
		win_data->var.julia_c.im += .1;
	mlx_destroy_image(win_data->mlx_ptr, win_data->img_ptr);
	ft_frac_algo(win_data);
	res = mlx_put_image_to_window(win_data->mlx_ptr, win_data->win_ptr,
		win_data->img_ptr, 0, 0);
	return (0);
}

void	mlx_win_gen(int	frac_type)
{
	t_win_data win_data;
	int			res;

	ft_init_data(&win_data, frac_type);
	win_data.mlx_ptr = mlx_init();
	win_data.win_ptr = mlx_new_window(win_data.mlx_ptr, 800, 600, "fract'ol");

	ft_frac_algo(&win_data);

	res = mlx_put_image_to_window(win_data.mlx_ptr, win_data.win_ptr, win_data.img_ptr, 0, 0);
	mlx_key_hook(win_data.win_ptr, get_key, &(win_data));
	mlx_loop(win_data.mlx_ptr);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putstr("usage : ./fractol <fractal type>\n");
        return (0);
    }
	if (ft_strncmp(av[1], "julia", 5) == 0)
		mlx_win_gen(1);
    return (0);
}