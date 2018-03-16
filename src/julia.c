/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:17:34 by jlange            #+#    #+#             */
/*   Updated: 2017/05/23 17:10:27 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_init1(t_frac *frac, t_mlx *mlx, int i)
{
	frac->mlx = mlx;
	frac->min = (WIN_X / THREAD) * i + 0.5;
	frac->max = (WIN_X / THREAD) * (i + 1) + 0.5;
	frac->zoom_x = WIN_X / (mlx->ens1.x2 - mlx->ens1.x1);
	frac->zoom_y = WIN_Y / (mlx->ens1.y2 - mlx->ens1.y1);
	frac->y = 0;
}

static inline void	ft_calc(t_frac f, long double c_r, long double c_i)
{
	t_calc			c;
	long double		tmp;

	c.z_r = f.x / f.zoom_x + f.mlx->ens1.x1;
	c.z_i = f.y / f.zoom_y + f.mlx->ens1.y1;
	c.i = 0;
	while (c.z_r * c.z_r + c.z_i * c.z_i < 4 && c.i < f.mlx->iter)
	{
		tmp = c.z_r;
		c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + c_r;
		c.z_i = 2 * c.z_i * tmp + c_i;
		++c.i;
	}
	if (c.i == f.mlx->iter)
		ft_pixel_put(f.mlx, f.x, f.y, 0x00);
	else
		ft_pixel_put(f.mlx, f.x, f.y, ft_rgb(c.i * 255 / f.mlx->iter,
					f.mlx->color));
}

void				*julia1(void *thrd)
{
	t_frac f;

	ft_init1(&f, ((t_thrd*)thrd)->mlx, ((t_thrd*)thrd)->i);
	while (f.y < WIN_Y)
	{
		f.x = f.min;
		while (f.x < f.max)
		{
			ft_calc(f, f.mlx->c_r, f.mlx->c_i);
			++f.x;
		}
		++f.y;
	}
	pthread_exit(NULL);
}

void				ft_julia(t_mlx *mlx)
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
		if (pthread_create(&t[i].t, NULL, julia1, &t[i]))
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

void				init_julia(t_mlx *mlx)
{
	ft_julia(mlx);
}
