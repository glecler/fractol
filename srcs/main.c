#include "fractol.h"

void	mlx_win_gen(int	frac_type)
{
	t_win_data win_data;

	ft_init_data(&win_data, frac_type);
	win_data.mlx_ptr = mlx_init();
	win_data.win_ptr = mlx_new_window(win_data.mlx_ptr, 800, 600, "fract'ol");
	ft_frac_ui(&win_data);
	ft_frac_multithread(&win_data);
	mlx_key_hook(win_data.win_ptr, get_key, &(win_data));
	mlx_mouse_hook(win_data.win_ptr, get_mouse, &(win_data));
	mlx_hook(win_data.win_ptr, 6, 0, &get_drag, &(win_data));
	
	mlx_loop(win_data.mlx_ptr);
	 if (win_data.autozoom == 1 && win_data.step.re > 0.0000000000001)
        get_mouse(4, 300, 300, &win_data);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putstr("usage : ./fractol <fractal type>\n");
        return (0);
    }
	if (ft_strncmp(av[1], "julia_v2", 8) == 0)
		mlx_win_gen(3);
	if (ft_strncmp(av[1], "julia", 5) == 0)
		mlx_win_gen(1);
	if (ft_strncmp(av[1], "mandelbrot", 9) == 0)
		mlx_win_gen(2);
    return (0);
}