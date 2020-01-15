#include "fractol.h"

void	ft_apply_color(t_win_data *win_data, float rank)
{
	
if (rank >= win_data->var.niter)
		rank = 0;
	win_data->color[0] = ((int)((win_data->rgb[0]) * rank));
	win_data->color[1] = ((int)((win_data->rgb[1]) * rank));
	win_data->color[2] = ((int)((win_data->rgb[2]) * rank));
}

int		ft_put_pixel_img(t_win_data *data, int x, int y, char *color)
{
	char	*cpy;

	cpy = data->addr;
	data->addr += y * data->size_line + x * 4;
	*(data->addr) = color[0];
    *(data->addr + 1) = color[1];
    *(data->addr + 2) = color[2];
	data->addr = cpy;
	return (1);
}