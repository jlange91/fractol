/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:27:28 by jlange            #+#    #+#             */
/*   Updated: 2017/05/23 16:27:41 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_mlx *mlx)
{
	long double xu;
	long double yu;

	mlx->h *= 0.9;
	xu = (mlx->ens1.x2 + mlx->ens1.x1) * 0.5;
	yu = (mlx->ens1.y2 + mlx->ens1.y1) * 0.5;
	mlx->ens1.x1 = xu - mlx->h;
	mlx->ens1.x2 = xu + mlx->h;
	mlx->ens1.y1 = yu - mlx->h;
	mlx->ens1.y2 = yu + mlx->h;
}

void	ft_dezoom(t_mlx *mlx)
{
	long double xu;
	long double yu;

	mlx->h /= 0.9;
	xu = (mlx->ens1.x2 + mlx->ens1.x1) * 0.5;
	yu = (mlx->ens1.y2 + mlx->ens1.y1) * 0.5;
	mlx->ens1.x1 = xu - mlx->h;
	mlx->ens1.x2 = xu + mlx->h;
	mlx->ens1.y1 = yu - mlx->h;
	mlx->ens1.y2 = yu + mlx->h;
}
