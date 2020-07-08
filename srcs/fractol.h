/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:52:25 by glecler           #+#    #+#             */
/*   Updated: 2020/01/28 23:19:36 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

typedef	struct	s_complex
{
	long double		re;
	long double		im;
}				t_complex;

typedef	struct	s_var
{
	t_complex	julia_c;
	t_complex	mandel_z;
	t_complex	param;
	int			niter;
}				t_var;

typedef	struct	s_win_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr[8];
	int					bpp;
	int					endian;
	int					size_line;
	t_complex			step;
	char				*addr;
	int					(*f)(t_var);
	long double			re_min;
	long double			re_max;
	long double			im_min;
	long double			im_max;
	char				color[3];
	t_var				var;
	int					flick;
	int					center;
	float				rgb[3];
}				t_win_data;

typedef	struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

/*
** main.c
*/

void			mlx_win_gen(int frac_type);

/*
**key_handler.c
*/

int				get_key(int key, void *param);
int				get_mouse(int button, int x, int y, void *param);
void			ft_zoom(t_win_data *win_data, int x, int y);
void			ft_unzoom(t_win_data *win_data, int x, int y);
void			ft_move(t_win_data *win_data, int key);
int				get_drag(int x, int y, t_win_data *win_data);
void			ft_center(t_win_data *win_data, int x, int y);
void			left_click_mouse(t_win_data *win_data, int button);

/*
**utilitaries.c
*/

void			ft_init_coord(t_coord *coord);
void			ft_init_param(t_complex *param, t_win_data *win_data);
void			ft_init_var(t_var *var, int frac_type);
void			ft_init_data(t_win_data *win_data, int frac_type);
void			ft_init_mlx(t_win_data *win_data);

/*
**algo.c
*/

void			*ft_thread_calc(void *arg);
void			ft_frac_multithread(t_win_data *win_data, int i);
int				ft_julia_f(t_var var);
int				ft_mandel(t_var var);
int				ft_julia_v2(t_var var);

/*
**img_draw.c
*/

char			*ft_color_pick(char *color, int rank, int niter);
void			ft_apply_color(t_win_data *win_data, float rank);
int				ft_put_pixel_img(t_win_data *data, int x, int y, char *color);

/*
**complex.c
*/

t_complex		ft_cplx_add(t_complex c, t_complex s);
t_complex		ft_cplx_mult(t_complex c, t_complex s);
int				ft_cplx_norme(t_complex c);

/*
**user_interface
*/

void			ft_frac_ui(t_win_data *win_data);
void			ft_frac_sidebar(t_win_data *win_data);
void			ft_frac_caption(t_win_data *win_data);
void			ft_frac_caption_next(t_win_data *win_data);
void			ft_coord_button(t_win_data *win_data, int x, int y);

#endif
