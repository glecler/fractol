#include "fractol.h"

void	ft_init_coord(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
}

void	ft_init_param(t_complex *param, t_win_data *win_data)
{
	param->re = win_data->re_min;
	param->im = win_data->im_min;
}

void	ft_init_data(t_win_data *win_data)
{
	win_data->mlx_ptr = 0;
	win_data->win_ptr = 0;
	win_data->img_ptr = 0;
	win_data->bpp = 24;
	win_data->endian = 0;
	win_data->size_line = 800 * 3;
	

	win_data->f = 0;
	win_data->re_min = -2;
	win_data->im_min = -2;
	win_data->step = 4.0 / 600.0;
	win_data->re_max = 600 * win_data->step + win_data->re_min;
	win_data->im_max = win_data->re_max;
	win_data->zoom = 1;
	ft_init_var(&(win_data->var));
}

void	ft_init_var(t_var *var)
{
	var->rank = 0;
	var->julia_c.re = 0;
	var->julia_c.im = 0;
	var;
}