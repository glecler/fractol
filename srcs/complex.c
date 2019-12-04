#include "fractol.h"

t_complex 	ft_cplx_add(t_complex c, t_complex s)
{
	t_complex sum;
	sum.im = c.im + s.im;
	sum.re = c.re + s.re;		
}

t_complex ft_cplx_mult(t_complex c, t_complex s)
{
	t_complex prod;
	prod.re = c.re * s.re - c.im * s.im;
	prod.im = c.re * s.im + c.im * s.re;
}

int		ft_cplx_norme(t_complex c)
{
	return (sqrt(c.re * c.re + c.im * c.im));
}