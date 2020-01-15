#include "fractol.h"

void	*ft_thread_calc(void *arg)
{
	t_coord coord;
	t_win_data *win_data;
	win_data = ((t_win_data *)arg);
	float rank;
	float buff;
	buff = 0;
	ft_init_coord(&coord);
	while (coord.x < 150)
	{
		while (coord.y < 600)
		{	
			win_data->var.mandel_z.re = 0;
			win_data->var.mandel_z.im = 0;
			rank = (*win_data->f)(win_data->var);
			if (rank != buff)
				ft_apply_color(win_data, rank);
			buff = rank;
			ft_put_pixel_img(win_data, coord.x, coord.y, win_data->color);
			win_data->var.param.im += win_data->step.im;
			coord.y += 1;

		}
		win_data->var.param.re += win_data->step.re;
		win_data->var.param.im = win_data->im_min;
		coord.x += 1;
		coord.y = 0;
	}
	return (0);
}

void	ft_frac_multithread(t_win_data *win_data)
{
	int ret;
	pthread_t threads[4];
	int i;
	t_win_data data[4];

	i = 0;
	while (i < 4)
	{
		win_data->img_ptr[i] = mlx_new_image(win_data->mlx_ptr, 150, 600);
		win_data->addr = mlx_get_data_addr(win_data->img_ptr[i], &(win_data->bpp),
			&(win_data->size_line), &(win_data->endian));
		win_data->var.param.re = win_data->re_min + win_data->step.re
			* i * 150;
		win_data->var.param.im = win_data->im_min;
		data[i] = *win_data;
		ret = pthread_create(&threads[i], NULL, &ft_thread_calc, &data[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ret = pthread_join(threads[i], NULL);
		ret = mlx_put_image_to_window(win_data->mlx_ptr, win_data->win_ptr, win_data->img_ptr[i], 150 * i, 0);
		mlx_destroy_image(win_data->mlx_ptr, win_data->img_ptr[i]);
		i++;
	}
}

int ft_julia_f(t_var var)
{
	int i;

	i = 0;
	while (ft_cplx_norme(var.param) < 2 && i < var.niter)
	{
		i += 1;
		var.param = ft_cplx_add(ft_cplx_mult(var.param, var.param), var.julia_c);
	}
	return (i);
}

int ft_julia_v2(t_var var)
{
	int i;

	i = 0;
	while (ft_cplx_norme(var.param) < 2 && i < var.niter)
	{
		i += 1;
		var.param = ft_cplx_add(ft_cplx_mult(ft_cplx_mult(var.param, var.param), var.param), var.julia_c);
	}
	return (i);
}

int	ft_mandel(t_var var)
{
	int i;

	i = 0;
	while (ft_cplx_norme(var.mandel_z) < 2 && i < var.niter)
	{
		var.mandel_z = ft_cplx_add(ft_cplx_mult(var.mandel_z, var.mandel_z), var.param);
		i++;
	}
	return (i);
}