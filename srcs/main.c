#include "fractol.h"

void	mlx_win_gen(int	frac_type)
{
	t_win_data win_data;
	int			res;

	ft_init_data(&win_data, frac_type);
	win_data.mlx_ptr = mlx_init();
	win_data.win_ptr = mlx_new_window(win_data.mlx_ptr, 800, 600, "fract'ol");

	ft_frac_algo(&win_data);

	res = mlx_put_image_to_window(win_data.mlx_ptr, win_data.win_ptr, win_data.img_ptr, 0, 0);
	//mlx_key_hook(win_data.win_ptr, get_key, &(data));
	mlx_loop(win_data.mlx_ptr);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putstr("usage : ./fractol <fractal type>\n");
        return (0);
    }
	if (av[1] == "julia")
		mlx_win_gen(1);
    return (0);
}