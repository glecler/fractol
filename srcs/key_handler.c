#include "fractol.h"

void	ft_zoom(t_win_data *win_data, int x, int y)
{
    win_data->im_min -= win_data->step * (300 - y);	
    win_data->re_min += win_data->step * (x - 300);
    win_data->re_min += win_data->step * 100;
    win_data->re_max -= win_data->step * 100;
    win_data->im_min += win_data->step * 100;
    win_data->im_max -= win_data->step * 100;
    win_data->step = (win_data->im_max - win_data->im_min) / 600.0;
}

void		ft_unzoom(t_win_data *win_data, int x, int y)
{
	win_data->im_min -= win_data->step * (300 - y);	
    win_data->re_min += win_data->step * (x - 300);
    win_data->re_min -= win_data->step * 100;
    win_data->re_max += win_data->step * 100;
    win_data->im_min -= win_data->step * 100;
    win_data->im_max += win_data->step * 100;
    win_data->step = (win_data->im_max - win_data->im_min) / 600.0;
    
}

void        ft_move(t_win_data *win_data, int key)
{
    if (key == 123)
        win_data->re_min -= 100 * win_data->step;
    if (key == 124)
        win_data->re_min += 100 * win_data->step;
    if (key == 126)
        win_data->im_min -= 100 * win_data->step;
    if (key == 125)
        win_data->im_min += 100 * win_data->step;
    win_data->im_max = 600 * win_data->step + win_data->im_min;
    win_data->re_max = 600 * win_data->step + win_data->re_min;
}

int		get_key(int key, void *param)
{
	t_win_data *win_data;

	win_data = param;
	if (key == 126 || key == 123 || key == 124 || key == 125)
		ft_move(win_data, key);
	ft_frac_multithread(win_data);
	return (0);
}
int		get_mouse(int button, int x, int y, void *param)
{
	t_win_data *win_data;

	win_data = param;
    if (button == 4)
        ft_zoom(win_data, x, y);
    if (button == 5)
        ft_unzoom(win_data, x, y);
	ft_frac_multithread(win_data);
	return (0);
}

int     get_drag(int x, int y, t_win_data *win_data)
{
    win_data->var.julia_c.re = x / 200.0 - 2.5;
    win_data->var.julia_c.im = y / 200.0 - 2.5;
    ft_frac_multithread(win_data);
    return (0);
}