/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tapis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:03:50 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 13:32:02 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline int	ft_calc(int tx, int ty)
{
	while (tx > 0 || ty > 0)
	{
		if (tx % 2 == 1 && ty % 2 == 1)
			return (1);
		ty /= 3;
		tx /= 3;
	}
	return (0);
}

void				*tapis1(void *thrd)
{
	t_frac f;

	f.y = 0;
	f.mlx = ((t_thrd*)thrd)->mlx;
	f.min = (WIN_X / THREAD) * ((t_thrd*)thrd)->i + 0.5;
	f.max = (WIN_X / THREAD) * (((t_thrd*)thrd)->i + 1) + 0.5;
	while (f.y < WIN_Y)
	{
		f.x = f.min;
		while (f.x < f.max)
		{
			if (ft_calc(f.x, f.y))
				ft_pixel_put(f.mlx, f.x, f.y, 0x5341);
			++f.x;
		}
		++f.y;
	}
	pthread_exit(NULL);
}

void				ft_tapis(t_mlx *mlx)
{
	int		bpb;
	int		size_l;
	int		endian;
	t_thrd	t[THREAD];
	int		i;

	i = 0;
	mlx->mlx_img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx->str_img = mlx_get_data_addr(mlx->mlx_img, &bpb, &size_l, &endian);
	mlx->img = (unsigned int *)mlx->str_img;
	while (i < THREAD)
	{
		t[i].i = i;
		t[i].mlx = mlx;
		if (pthread_create(&t[i].t, NULL, tapis1, &t[i]))
			exit(EXIT_FAILURE);
		++i;
	}
	i = -1;
	while (++i < THREAD)
		if (pthread_join(t[i].t, NULL))
			exit(EXIT_FAILURE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mlx_img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->str_img);
	ft_text(mlx);
}

void				init_tapis(t_mlx *mlx)
{
	ft_tapis(mlx);
}
