/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:31:42 by jlange            #+#    #+#             */
/*   Updated: 2017/05/23 18:01:44 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_calc_tmp(t_calc *c, long double tmp, int opt)
{
	if (opt == 4)
	{
		c->z_r = c->z_r * c->z_r * c->z_r * c->z_r * c->z_r - 10 * c->z_r *
			c->z_r * c->z_r * c->z_i * c->z_i + 5 * c->z_r * c->z_i * c->z_i *
			c->z_i * c->z_i + c->c_r;
		c->z_i = 5 * tmp * tmp * tmp * tmp * c->z_i -
			10 * tmp * tmp * c->z_i * c->z_i * c->z_i + c->z_i * c->z_i * c->z_i
			* c->z_i * c->z_i + c->c_i;
	}
	else if (opt == 5)
	{
		c->z_r = c->z_r * c->z_r * c->z_r * c->z_r * c->z_r * c->z_r - 15 *
			c->z_r * c->z_r * c->z_r * c->z_r * c->z_i * c->z_i + 15 * c->z_r *
			c->z_r * c->z_i * c->z_i * c->z_i * c->z_i - c->z_i * c->z_i *
			c->z_i * c->z_i * c->z_i * c->z_i + c->c_r;
		c->z_i = 6 * tmp * tmp * tmp * tmp * tmp *
			c->z_i - 20 * tmp * tmp * tmp * c->z_i * c->z_i * c->z_i + 6 * tmp *
			c->z_i * c->z_i * c->z_i * c->z_i * c->z_i + c->c_i;
	}
}

void				ft_calc_power(t_calc *c, long double tmp, int opt)
{
	if (opt == 1)
	{
		c->z_r = c->z_r * c->z_r - c->z_i * c->z_i + c->c_r;
		c->z_i = 2 * c->z_i * tmp + c->c_i;
	}
	else if (opt == 2)
	{
		c->z_r = c->z_r * c->z_r * c->z_r - 3 * c->z_r * c->z_i * c->z_i +
			c->c_r;
		c->z_i = 3 * tmp * tmp * c->z_i - c->z_i *
			c->z_i * c->z_i + c->c_i;
	}
	else if (opt == 3)
	{
		c->z_r = c->z_r * c->z_r * c->z_r * c->z_r - 6 * c->z_r *
			c->z_r * c->z_i * c->z_i + c->z_i * c->z_i * c->z_i * c->z_i +
			c->c_r;
		c->z_i = 4 * tmp * tmp * tmp * c->z_i - 4 * tmp
			* c->z_i * c->z_i * c->z_i + c->c_i;
	}
	else
		ft_calc_tmp(c, tmp, opt);
}

static inline void	ft_calc_tmp2(t_calc *c, long double tmp, int opt)
{
	if (opt == 4)
	{
		c->z_r = c->z_r * c->z_r * c->z_r * c->z_r * c->z_r - 10 * c->z_r *
			c->z_r * c->z_r * c->z_i * c->z_i + 5 * c->z_r * c->z_i * c->z_i *
			c->z_i * c->z_i + c->c_r;
		c->z_i = -5 * tmp * tmp * tmp * tmp * c->z_i +
			10 * tmp * tmp * c->z_i * c->z_i * c->z_i - c->z_i * c->z_i * c->z_i
			* c->z_i * c->z_i + c->c_i;
	}
	else if (opt == 5)
	{
		c->z_r = c->z_r * c->z_r * c->z_r * c->z_r * c->z_r * c->z_r - 15 *
			c->z_r * c->z_r * c->z_r * c->z_r * c->z_i * c->z_i + 15 * c->z_r *
			c->z_r * c->z_i * c->z_i * c->z_i * c->z_i - c->z_i * c->z_i *
			c->z_i * c->z_i * c->z_i * c->z_i + c->c_r;
		c->z_i = -6 * tmp * tmp * tmp * tmp * tmp *
			c->z_i + 20 * tmp * tmp * tmp * c->z_i * c->z_i * c->z_i - 6 * tmp *
			c->z_i * c->z_i * c->z_i * c->z_i * c->z_i + c->c_i;
	}
}

void				ft_calc_power2(t_calc *c, long double tmp, int opt)
{
	if (opt == 1)
	{
		c->z_r = c->z_r * c->z_r - c->z_i * c->z_i + c->c_r;
		c->z_i = -2 * c->z_i * tmp + c->c_i;
	}
	else if (opt == 2)
	{
		c->z_r = c->z_r * c->z_r * c->z_r - 3 * c->z_r * c->z_i * c->z_i +
			c->c_r;
		c->z_i = -3 * tmp * tmp * c->z_i + c->z_i *
			c->z_i * c->z_i + c->c_i;
	}
	else if (opt == 3)
	{
		c->z_r = c->z_r * c->z_r * c->z_r * c->z_r - 6 * c->z_r *
			c->z_r * c->z_i * c->z_i + c->z_i * c->z_i * c->z_i * c->z_i +
			c->c_r;
		c->z_i = -4 * tmp * tmp * tmp * c->z_i + 4 * tmp
			* c->z_i * c->z_i * c->z_i + c->c_i;
	}
	else
		ft_calc_tmp2(c, tmp, opt);
}
