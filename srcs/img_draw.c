#include "fractol.h"

char	*ft_color_pick(char *color, int rank)
{
	if (rank >= 29)
	{
		ft_apply_color(color, "000000000");
		return (color);
	}
	rank = rank % 6;
	if (rank == 1 || rank == 0)
		ft_apply_color(color, "245127094");
	if (rank == 2)
		ft_apply_color(color, "243196046");
	if (rank == 3)
		ft_apply_color(color, "232252000");
	if (rank == 4)
		ft_apply_color(color, "134155096");
	if (rank == 5)
		ft_apply_color(color, "143155096");
	if (rank == 6)
		ft_apply_color(color, "134123036");
	return (color);
}

char	*ft_apply_color(char *color, char *rgb)
{
	color[0] = rgb[0] * 100 + rgb[1] * 10 + rgb[2] - 5328;
	color[1] = rgb[3] * 100 + rgb[4] * 10 + rgb[5] - 5328;
	color[2] = rgb[6] * 100 + rgb[7] * 10 + rgb[8] - 5328;
	return (color);
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