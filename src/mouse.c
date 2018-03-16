/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:17:23 by jlange            #+#    #+#             */
/*   Updated: 2017/05/23 16:31:32 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_mouse_moove(int x, int y, t_mlx *mlx)
{
	t_remap mx;
	t_remap my;

	if (mlx->opt == 2 && mlx->julia)
	{
		mx.in_min = 0;
		mx.in_max = WIN_X;
		mx.out_min = -2.1;
		mx.out_max = 0.6;
		mlx->c_r = ft_remap2(x, mx);
		my.in_min = 0;
		my.in_max = WIN_Y;
		my.out_min = -1.2;
		my.out_max = 1.2;
		mlx->c_i = ft_remap2(y, my);
		ft_tmp(mlx);
	}
	return (0);
}

static inline void	mol_zoom(t_mlx *mlx, long double xu, long double yu)
{
	mlx->h *= 0.9;
	mlx->ens1.x1 = xu - mlx->h;
	mlx->ens1.x2 = xu + mlx->h;
	mlx->ens1.y1 = yu - mlx->h;
	mlx->ens1.y2 = yu + mlx->h;
}

static inline void	mol_dezoom(t_mlx *mlx, long double xu, long double yu)
{
	mlx->h /= 0.9;
	mlx->ens1.x1 = xu - mlx->h;
	mlx->ens1.x2 = xu + mlx->h;
	mlx->ens1.y1 = yu - mlx->h;
	mlx->ens1.y2 = yu + mlx->h;
}

#define PURCENT 15

int					ft_mouse_click(int but, int x, int y, t_mlx *mlx)
{
	long double	xu;
	long double	yu;
	int x2;
	int y2;
	int middle;
	int purcent;

	if (but == 1)
		mlx->julia = (mlx->julia == true) ? false : true;
	if (but == 4 || but == 5)
	{
		middle = WIN_X / 2;
		purcent = WIN_X / PURCENT;
		x2 = x * (purcent + purcent) / WIN_X + middle - purcent;
		xu = x2 * (mlx->ens1.x2 - mlx->ens1.x1) / WIN_X + mlx->ens1.x1;
		middle = WIN_Y / 2;
		purcent = WIN_Y / PURCENT;
		y2 = y * (purcent + purcent) / WIN_Y + middle - purcent;
		yu = y2 * (mlx->ens1.y2 - mlx->ens1.y1) / WIN_Y + mlx->ens1.y1;
		(but == 4) ? mol_zoom(mlx, xu, yu) : mol_dezoom(mlx, xu, yu);
		ft_tmp(mlx);
	}
	return (0);
}
