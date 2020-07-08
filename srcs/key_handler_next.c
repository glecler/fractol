/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 23:39:54 by glecler           #+#    #+#             */
/*   Updated: 2020/01/28 23:40:10 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_win_data *win_data, int key)
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

void	ft_center(t_win_data *win_data, int x, int y)
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
	if (win_data->var.niter < 100)
		win_data->var.niter += 10;
}

void	ft_unzoom(t_win_data *win_data, int x, int y)
{
	if (win_data->center == 1)
		ft_center(win_data, x, y);
	win_data->re_min -= win_data->step.re * 100;
	win_data->re_max += win_data->step.re * 100;
	win_data->im_min -= win_data->step.im * 100;
	win_data->im_max += win_data->step.im * 100;
	win_data->step.re = (win_data->re_max - win_data->re_min) / 600.0;
	win_data->step.im = (win_data->im_max - win_data->im_min) / 600.0;
}
