#include <math.h>

typedef struct s_win_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bpp;
	int			endian;
	int			size_line;
	double		step;
	char		*addr;
	void		(*f)();
	int			re_min;
	int			re_max;
	int			im_min;
	int			im_max;
	char		color[3];
	t_var		var;
    double      zoom;
}				t_win_data;

typedef struct s_var
{
	int			rank;
	t_complex	julia_c;
	t_complex	param;		
}				t_var;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_coord
{
	int		x;
	int		y;
}				t_coord;

void	    ft_init_coord(t_coord *coord);
void	    ft_init_param(t_complex *param, t_win_data *win_data);
void	    ft_frac_algo(t_win_data *win_data);
void	    ft_color_pick(char *color, int rank);
void	    ft_appy_color(char *color, char *rgb);
t_complex 	ft_cplx_add(t_complex c, t_complex s);
t_complex   ft_cplx_mult(t_complex c, t_complex s);
int		    ft_cplx_norme(t_complex c);
int         ft_julia_f(t_var var);
int	    	ft_is_bound(int (*f)(t_var), t_complex param, t_win_data *win_data);
void	    mlx_win_gen(int	frac_type);
int		    ft_put_pixel_img(t_win_data *data, int x, int y, char *color);