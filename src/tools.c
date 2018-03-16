/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:51:53 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 11:34:05 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int test;

	test = (y * WIN_X) + x;
	if ((y > 0 && y < WIN_Y) && (x > 0 && x < WIN_X))
		mlx->img[test] = color;
}

int				ft_redcross(void *mlx)
{
	t_mlx *mlx2;

	mlx2 = (t_mlx*)mlx;
	exit(0);
}

long double		ft_remap2(int x, t_remap info)
{
	long double	ret;

	ret = ((x - info.in_min) * (info.out_max - info.out_min) / (info.in_max -
	info.in_min) + info.out_min);
	return (ret);
}

void			ft_tmp(t_mlx *mlx)
{
	if (mlx->opt == 1)
		ft_mandelbrot(mlx);
	else if (mlx->opt == 2)
		ft_julia(mlx);
	else if (mlx->opt == 3)
		ft_burningship(mlx);
	else if (mlx->opt == 4)
		ft_mandelbar(mlx);
	else if (mlx->opt == 5)
		ft_tapis(mlx);
	else if (mlx->opt == 6)
		ft_buddha(mlx);
}

void			ft_lst_add(t_coord **begin, long double x, long double y)
{
	t_coord *copy;
	t_coord *new;

	copy = *begin;
	new = NULL;
	new = malloc(sizeof(t_coord));
	if (!new)
		exit(0);
	if (new)
	{
		new->x = x;
		new->y = y;
		new->next = NULL;
	}
	if (copy)
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
	else
		*begin = new;
}
