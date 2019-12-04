#include "fractol.h"

void	ft_frac_algo(t_win_data *win_data)
{
	t_complex	param;
	t_coord		coord;
	int			rank;

	ft_init_coord(&coord);
	ft_init_param(&param, win_data);
    win_data->f(t_var) = &ft_julia_f;
	win_data->img_ptr = mlx_new_image(win_data->mlx_ptr, 600, 600);
	win_data->addr = mlx_get_data_addr(win_data->img_ptr, &(win_data->bpp),
		&(win_data->size_line), &(win_data->endian));
	while (coord.x < 600)
	{
		while (coord.y < 600)
		{
			rank = ft_is_bound(win_data->f, param, win_data);
			ft_color_pick(win_data->color, rank);
			ft_put_pixel_img(win_data, coord.x, coord.y, win_data->color);
			param.im += win_data->step;
			coord.y += 1;

		}
		param.re += win_data->step;
		param.im = win_data->im_min;
		coord.x += 1;
		coord.y = 0;
	}
}

int ft_julia_f(t_var var)
{
	var.rank += 1;
	var.param = ft_cplx_add(ft_cplx_mult(var.param, var.param), var.julia_c);
	if (ft_cplx_norme(var.param) > 2 && var.rank < 1000)
		return (var.rank);
	ft_julia_f(var);
	return (var.rank);
}

int		ft_is_bound(int (*f)(t_var), t_complex param, t_win_data *win_data)
{
    win_data->var.rank = 0;
	win_data->var.param = param;
    win_data->var.rank = (*f)(win_data->var);
    return (win_data->var.rank);
}