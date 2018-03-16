/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 22:33:17 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 13:23:10 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define TAB f->tab[(int)begin->y][(int)begin->x]

static inline void	ft_init1(t_frac *frac, t_mlx *mlx, int y)
{
	int x;

	frac->mlx = mlx;
	frac->zoom_x = WIN_X / (mlx->ens1.x2 - mlx->ens1.x1);
	frac->zoom_y = WIN_Y / (mlx->ens1.y2 - mlx->ens1.y1);
	frac->y = 0;
	frac->tab = malloc(sizeof(long double*) * WIN_Y);
	if (!frac->tab)
		exit(0);
	while (++y < WIN_Y)
	{
		frac->tab[y] = malloc(sizeof(long double) * WIN_X);
		if (!frac->tab[y])
			exit(0);
	}
	y = 0;
	while (y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			frac->tab[y][x] = 0;
		++y;
	}
}

static inline void	ft_calc(t_frac *f, t_coord *begin)
{
	t_calc		c;

	c.c_i = f->x / f->zoom_x + f->mlx->ens1.x1;
	c.c_r = f->y / f->zoom_y + f->mlx->ens1.y1;
	c.z_r = 0;
	c.z_i = 0;
	c.i = -1;
	while (c.z_r * c.z_r + c.z_i * c.z_i < 4 && ++c.i < f->mlx->iter)
	{
		ft_calc_power(&c, c.z_r, f->mlx->test);
		ft_lst_add(&begin, (c.z_i - f->mlx->ens1.x1) * f->zoom_x,
				(c.z_r - f->mlx->ens1.y1) * f->zoom_y);
	}
	if (c.i != f->mlx->iter)
		while (begin)
		{
			if ((begin->y >= 0 && begin->y < WIN_Y) && (begin->x >= 0 &&
					begin->x < WIN_X))
				TAB++;
			begin = begin->next;
		}
	free_lst(&begin);
}

void				buddha1(t_mlx *mlx)
{
	t_frac f;

	ft_init1(&f, mlx, -1);
	while (f.y < WIN_Y)
	{
		f.x = 0;
		while (f.x < WIN_X)
		{
			ft_calc(&f, NULL);
			++f.x;
		}
		++f.y;
	}
	f.y = 0;
	while (f.y < WIN_Y)
	{
		f.x = -1;
		while (++f.x < WIN_X)
			ft_pixel_put(mlx, f.x, f.y, ft_b(f.tab[(int)f.y][(int)f.x],
						f.mlx->color));
		f.y++;
	}
	free_tab_2d(f.tab);
}

void				ft_buddha(t_mlx *mlx)
{
	int		bpb;
	int		size_l;
	int		endian;
	int		i;

	i = 0;
	mlx->mlx_img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx->str_img = mlx_get_data_addr(mlx->mlx_img, &bpb, &size_l, &endian);
	mlx->img = (unsigned int *)mlx->str_img;
	buddha1(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mlx_img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->str_img);
	ft_text(mlx);
}

void				init_buddha(t_mlx *mlx)
{
	ft_buddha(mlx);
}
