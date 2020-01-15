#include "fractol.h"

void    ft_center(t_win_data *win_data, int x, int y)
{
    win_data->im_min -= win_data->step.im * (300 - y) * 0.5;	
    win_data->re_min += win_data->step.re * (x - 300) * 0.5;
    win_data->re_max += win_data->step.re * (x - 300) * 0.5;
    win_data->im_max -= win_data->step.im * (300 - y) * 0.5;
    win_data->step.re = (win_data->re_max - win_data->re_min) / 600.0;
    win_data->step.im = (win_data->im_max - win_data->im_min) / 600.0;
}

void	ft_zoom(t_win_data *win_data, int x, int y)
{
    if (win_data->center == 1)
        ft_center(win_data, x, y);
    win_data->re_min += win_data->step.re * 100;
    win_data->re_max -= win_data->step.re * 100;
    win_data->im_min += win_data->step.im * 100;
    win_data->im_max -= win_data->step.im * 100;
    win_data->step.re = (win_data->re_max - win_data->re_min) / 600.0;
    win_data->step.im = (win_data->im_max - win_data->im_min) / 600.0;
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 380, 000000000, ft_itoa((win_data->var.niter)));
    if (win_data->var.niter < 500)
        win_data->var.niter += 15;
    mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 380, 250255255, ft_itoa((win_data->var.niter)));
}

void		ft_unzoom(t_win_data *win_data, int x, int y)
{
	if (win_data->center == 1)
        ft_center(win_data, x, y);
    win_data->re_min -= win_data->step.re * 100;
    win_data->re_max += win_data->step.re * 100;
    win_data->im_min -= win_data->step.im * 100;
    win_data->im_max += win_data->step.im * 100;
    win_data->step.re = (win_data->re_max - win_data->re_min) / 600.0;
    win_data->step.im = (win_data->im_max - win_data->im_min) / 600.0;
    if (win_data->var.niter > 150)
        win_data->var.niter -= 15;
}

void        ft_move(t_win_data *win_data, int key)
{
    if (key == 123)
        win_data->re_min -= 100 * win_data->step.re;
    if (key == 124)
        win_data->re_min += 100 * win_data->step.re;
    if (key == 126)
        win_data->im_min -= 100 * win_data->step.im;
    if (key == 125)
        win_data->im_min += 100 * win_data->step.im;
    win_data->im_max = 600 * win_data->step.im + win_data->im_min;
    win_data->re_max = 600 * win_data->step.re + win_data->re_min;
}

int		get_key(int key, void *param)
{
	t_win_data *win_data;

	win_data = param;
    if (key == 53)
    {
        exit(0);
    }
	if (key == 126 || key == 123 || key == 124 || key == 125)
		ft_move(win_data, key);
    if (key == 1 && win_data->center == 0)
    {
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 320, 120120, ">");
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 330, 0, ">");
       win_data->center = 1;
    }
    else if (key == 1 && win_data->center == 1)
    {
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 320, 0, ">");
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 330, 120120, ">");
       win_data->center = 0;
    }
    ft_frac_multithread(win_data);
	return (0);
}
int		get_mouse(int button, int x, int y, void *param)
{
	t_win_data *win_data;

	win_data = param;
    if (x > 600)
    {
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 160, 000000000, ft_itoa((win_data->rgb[2])));
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 180, 000000000, ft_itoa((win_data->rgb[1])));
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 200, 000000000, ft_itoa((win_data->rgb[0])));
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 380, 000000000, ft_itoa((win_data->var.niter)));
        ft_coord_button(win_data, x, y);
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 160, 200000000, ft_itoa((win_data->rgb[2])));
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 180, 255000, ft_itoa((win_data->rgb[1])));
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 200, 255, ft_itoa((win_data->rgb[0])));
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 760, 380, 250255255, ft_itoa((win_data->var.niter)));
        ft_frac_multithread(win_data);

        return (0);
    }

    if (button == 4)
        ft_zoom(win_data, x, y);
    if (button == 5)
        ft_unzoom(win_data, x, y);
    if (button == 1 && win_data->flick == 0)
    {
        win_data->var.niter *= 10;
        win_data->flick = 1;
       
    }
    else if (button == 1 && win_data->flick == 1)
     {
        win_data->var.niter /= 10;
        win_data->flick = 0;
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 320, 0, ">");
        mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 330, 120120, ">");
     }
     if (button == 2)
        ft_center(win_data, x, y);
	ft_frac_multithread(win_data);
	return (0);
}

int     get_drag(int x, int y, t_win_data *win_data)
{
    if (win_data->flick == 0)
    {
        win_data->var.julia_c.re = x / 200.0 - 2.5;
        win_data->var.julia_c.im = y / 200.0 - 2.5;
        ft_frac_multithread(win_data);
    }
    return (0);
}