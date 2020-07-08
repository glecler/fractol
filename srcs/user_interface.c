/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:50:30 by glecler           #+#    #+#             */
/*   Updated: 2020/01/28 23:41:27 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_frac_sidebar(t_win_data *win_data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_apply_color(win_data, 2);
	while (x < 20)
	{
		while (y < 600)
		{
			ft_put_pixel_img(win_data, x, y, win_data->color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_frac_caption(t_win_data *win_data)
{
	int	ret;

	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		20, 255255255, "fract'ol!");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		50, 255230200, "left click to");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		70, 255230200, "lock c");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		90, 255255, "press esc to");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		110, 255255, "quit :(");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		140, 200120120, "choose colors!");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 650,
		160, 200000000, "R : +  -");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr,
		650, 180, 255000, "G : +  -");
	ft_frac_caption_next(win_data);
}

void	ft_frac_caption_next(t_win_data *win_data)
{
	int ret;

	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 650,
		200, 255, "B : +  -");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		230, 255255, "right click to");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		250, 255255, "center img");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		280, 255000255, "press s to");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		300, 255000255, "switch zoom modes");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		320, 255000255, " dynamic");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		330, 255000255, ">static");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		360, 134203067, "choose precision!");
	ret = mlx_string_put(win_data->mlx_ptr, win_data->win_ptr, 630,
		380, 134203067, "N : +  -");
}

void	ft_frac_ui(t_win_data *win_data)
{
	int ret;

	win_data->img_ptr[0] = mlx_new_image(win_data->mlx_ptr, 200, 600);
	win_data->addr = mlx_get_data_addr(win_data->img_ptr[0], &(win_data->bpp),
		&(win_data->size_line), &(win_data->endian));
	ft_frac_sidebar(win_data);
	ret = mlx_put_image_to_window(win_data->mlx_ptr, win_data->win_ptr,
		win_data->img_ptr[0], 600, 0);
	ret = mlx_destroy_image(win_data->mlx_ptr, win_data->img_ptr[0]);
	ft_frac_caption(win_data);
}

void	ft_coord_button(t_win_data *win_data, int x, int y)
{
	if (x >= 690 && x <= 700 && y >= 170 && y <= 180 && win_data->rgb[2] < 100)
		win_data->rgb[2] += 5;
	if (x >= 720 && x <= 730 && y >= 170 && y <= 180 && win_data->rgb[2] > 0)
		win_data->rgb[2] -= 5;
	if (x >= 690 && x <= 700 && y >= 190 && y <= 200 && win_data->rgb[1] < 100)
		win_data->rgb[1] += 5;
	if (x >= 720 && x <= 730 && y >= 190 && y <= 200 && win_data->rgb[1] > 0)
		win_data->rgb[1] -= 5;
	if (x >= 690 && x <= 700 && y >= 210 && y <= 220 && win_data->rgb[0] < 100)
		win_data->rgb[0] += 5;
	if (x >= 720 && x <= 730 && y >= 210 && y <= 220 && win_data->rgb[0] > 0)
		win_data->rgb[0] -= 5;
	if (x >= 670 && x <= 680 && y >= 390 && y <= 400)
		win_data->var.niter += 100;
	if (x >= 700 && x <= 710 && y >= 390 && y <= 400 && win_data->var.niter > 0)
		win_data->var.niter -= 100;
}
