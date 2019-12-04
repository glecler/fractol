#include "fractol.h"

char	*ft_color_pick(char *color, int rank)
{
	if (rank > 900)
	{
		ft_apply_color(color, "000000000");
		return (color);
	}
	while (rank > 56)
		rank -= 50;
	while (rank > 6)
	 	rank -= 6;
	if (rank == 1)
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
	int n;

	n = 0;
	while (n < 3)
	{
		color[n] = rgb[3 * n] * 100 + rgb[3 * n + 1] * 10 + rgb[3 * n + 2] - 5328;
		n += 1; 
	}
	return (color);
}

int		ft_put_pixel_img(t_win_data *data, int x, int y, char *color)
{
	char	*cpy;

	cpy = data->addr;
	if (y >= 600 || x >= 600 || x < 0 || y < 0)
		return (0);
	data->addr += y * data->size_line + x * (data->bpp / 8);
	*(data->addr) = color[0];
    *(data->addr + 1) = color[1];
    *(data->addr + 2) = color[2];
	data->addr = cpy;
	return (1);
}