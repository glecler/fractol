#include "fractol.h"

void	ft_init_coord(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
}

void	ft_init_param(t_complex *param, t_win_data *win_data)
{
	//param->re = win_data->re_min + win_data->step * win_data->i * 150;
	param->im = win_data->im_min;
}

void	ft_init_data(t_win_data *win_data, int frac_type)
{
	win_data->mlx_ptr = 0;
	win_data->win_ptr = 0;
	win_data->img_ptr[0] = 0;
	win_data->img_ptr[1] = 0;
	win_data->img_ptr[2] = 0;
	win_data->img_ptr[3] = 0;
	win_data->bpp = 3;
	win_data->endian = 0;
	win_data->size_line = 600 * 3;
	win_data->re_min = -2;
	win_data->im_min = -2;
	win_data->step = 4.0 / 600.0;
	win_data->re_max = 2;
	win_data->im_max = 2;
	if (frac_type == 1)
		win_data->f = &ft_julia_f;
	if (frac_type == 2)
		win_data->f = &ft_mandel;
	if (frac_type == 3)
		win_data->f = &ft_julia_v2;
	ft_init_var(&(win_data->var));
}

void	ft_init_var(t_var *var)
{
	var->julia_c.re = -0.39;
	var->julia_c.im = -0.58;
	var->mandel_z.im = 0;
	var->mandel_z.re = 0;
}