/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:21:21 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 13:40:45 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_display_hook4(int nb, t_mlx *mlx)
{
	if (nb == 18)
		mlx->opt = 1;
	else if (nb == 19)
		mlx->opt = 2;
	else if (nb == 20)
		mlx->opt = 3;
	else if (nb == 21)
		mlx->opt = 4;
	else if (nb == 23)
		mlx->opt = 5;
	else if (nb == 22)
		mlx->opt = 6;
	else if (nb == 15)
	{
		if (mlx->opt == 1 || mlx->opt == 4 || mlx->opt == 6)
		{
			mlx->test += (mlx->test == 5) ? -4 : 1;
			ft_tmp(mlx);
		}
	}
	if (nb >= 18 && nb <= 23)
		ft_tmp(mlx);
}

static inline void	ft_display_hook3(int nb, t_mlx *mlx)
{
	if (nb == UP)
	{
		mlx->ens1.y1 -= 0.6 * mlx->h;
		mlx->ens1.y2 -= 0.6 * mlx->h;
		ft_tmp(mlx);
	}
	else if (nb == 13)
	{
		mlx->ens1.x1 = -2;
		mlx->ens1.y1 = -2;
		mlx->ens1.x2 = 2;
		mlx->ens1.y2 = 2;
		mlx->h = 2;
		mlx->iter = ITER;
		ft_tmp(mlx);
	}
	else
		ft_display_hook4(nb, mlx);
}

static inline void	ft_display_hook2(int nb, t_mlx *mlx)
{
	if (nb == LEFT)
	{
		mlx->ens1.x1 -= 0.6 * mlx->h;
		mlx->ens1.x2 -= 0.6 * mlx->h;
		ft_tmp(mlx);
	}
	else if (nb == RIGHT)
	{
		mlx->ens1.x1 += 0.6 * mlx->h;
		mlx->ens1.x2 += 0.6 * mlx->h;
		ft_tmp(mlx);
	}
	else if (nb == DOWN)
	{
		mlx->ens1.y1 += 0.6 * mlx->h;
		mlx->ens1.y2 += 0.6 * mlx->h;
		ft_tmp(mlx);
	}
	else if (nb == COLOR)
	{
		mlx->color += (mlx->color == 10) ? -9 : 1;
		ft_tmp(mlx);
	}
	else
		ft_display_hook3(nb, mlx);
}

int					ft_display_hook(int nb, t_mlx *mlx)
{
	if (nb == ESC)
		exit(0);
	else if (nb == ZOOM)
	{
		ft_zoom(mlx);
		ft_tmp(mlx);
	}
	else if (nb == DEZOOM)
	{
		ft_dezoom(mlx);
		ft_tmp(mlx);
	}
	else if (nb == PLUS)
	{
		++mlx->iter;
		ft_tmp(mlx);
	}
	else if (nb == MINUS)
	{
		mlx->iter -= (mlx->iter > 1) ? 1 : 0;
		ft_tmp(mlx);
	}
	else
		ft_display_hook2(nb, mlx);
	return (0);
}
