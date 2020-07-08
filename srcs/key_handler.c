/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:56:38 by glecler           #+#    #+#             */
/*   Updated: 2020/01/29 01:41:23 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_key(int key, void *param)
{
	t_win_data *win_data;

	win_data = param;
	if (key == 53)
		exit(0);
	if (key == 126 || key == 123 || key == 124 || key == 125)
		ft_move(win_data, key);
	if (key == 1 && win_data->center == 0)
	{
		mlx_string_put(win_data->mlx_ptr, win_data->win_ptr,
			630, 320, 120120, ">");
		mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 330, 0, ">");
		win_data->center = 1;
	}
	else if (key == 1 && win_data->center == 1)
	{
		mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 320, 0, ">");
		mlx_string_put(win_data->mlx_ptr, win_data->win_ptr,
			630, 330, 120120, ">");
		win_data->center = 0;
	}
	ft_frac_multithread(win_data, 0);
	return (0);
}

void	left_click_mouse(t_win_data *win_data, int button)
{
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
		mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630, 330,
			120120, ">");
	}
}

int		get_mouse(int button, int x, int y, void *param)
{
	t_win_data *win_data;

	win_data = param;
	if (x > 600)
	{
		ft_coord_button(win_data, x, y);
		ft_frac_multithread(win_data, 0);
		return (0);
	}
	if (button == 4 && ft_abs(win_data->step.re > .0000000000000000001))
		ft_zoom(win_data, x, y);
	if (button == 5 && ft_abs(win_data->step.re) < .01)
		ft_unzoom(win_data, x, y);
	if (button == 1)
		left_click_mouse(win_data, button);
	if (button == 2)
		ft_center(win_data, x, y);
	ft_frac_multithread(win_data, 0);
	return (0);
}

int		get_drag(int x, int y, t_win_data *win_data)
{
	if (win_data->flick == 0)
	{
		win_data->var.julia_c.re = x / 200.0 - 2.5;
		win_data->var.julia_c.im = y / 200.0 - 2.5;
		ft_frac_multithread(win_data, 0);
	}
	return (0);
}
