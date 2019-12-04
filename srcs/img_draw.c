#include "fractol.h"

void	ft_color_pick(char *color, int rank)
{
	if (rank < 2)
		ft_apply_color(color, "255211025");
	if (rank < 4 && rank >= 2)
		ft_apply_color(color, "255144031");
	if (rank < 10 && rank >= 4)
		ft_apply_color(color, "255041117");
	if (rank < 15 && rank >= 10)
		ft_apply_color(color, "242034255");
	if (rank < 20 && rank >= 15)
		ft_apply_color(color, "140030255");
	if (rank > 20)
		ft_apply_color(color, "000000000");
	return (color);
}

void	ft_appy_color(char *color, char *rgb)
{
	int n;

	n = 0;
	while (n < 3)
	{
		color[n] = rgb[3 * n] * 100 + rgb[3 * n + 1] * 10 + rgb[3 * n + 2] - 3441;
		n += 1; 
	}
}

int		ft_put_pixel_img(t_win_data *data, int x, int y, char *color)
{
	char	*cpy;

	cpy = data->addr;
	if (y >= data->img_width || x >= data->img_width || x < 0 || y < 0)
		return (0);
	data->addr += y * data->size_line + x * (data->bpp / 8);
	*(data->addr) = color[0];
    *(data->addr + 1) = color[1];
    *(data->addr + 2) = color[2];
	data->addr = cpy;
	return (1);
}