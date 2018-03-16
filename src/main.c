/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:23:16 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 13:40:23 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init(int opt)
{
	t_mlx mlx;

	mlx.tab[0] = init_mandelbrot;
	mlx.tab[1] = init_julia;
	mlx.tab[2] = init_burningship;
	mlx.tab[3] = init_mandelbar;
	mlx.tab[4] = init_tapis;
	mlx.tab[5] = init_buddha;
	mlx.opt = opt;
	mlx.mlx = mlx_init();
	mlx.iter = ITER;
	mlx.color = 1;
	mlx.h = 2;
	mlx.ens1.x1 = -2;
	mlx.ens1.x2 = 2;
	mlx.ens1.y1 = -2;
	mlx.ens1.y2 = 2;
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Fractol");
	mlx.test = 1;
	mlx.c_r = -0.8;
	mlx.c_i = 0.2;
	mlx.julia = false;
	ft_zoom(&mlx);
	mlx.tab[opt - 1](&mlx);
	mlx_hook(mlx.win, 2, (1L << 0), ft_display_hook, &mlx);
	mlx_hook(mlx.win, 6, (1L << 6), ft_mouse_moove, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_click, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), ft_redcross, &mlx);
	mlx_loop(mlx.mlx);
}

void		ft_check_arg(char **av)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
		ft_init(1);
	else if (!ft_strcmp(av[1], "julia"))
		ft_init(2);
	else if (!ft_strcmp(av[1], "burningship"))
		ft_init(3);
	else if (!ft_strcmp(av[1], "mandelbar"))
		ft_init(4);
	else if (!ft_strcmp(av[1], "tapis"))
		ft_init(5);
	else if (!ft_strcmp(av[1], "buddha"))
		ft_init(6);
	else
	{
		ft_putstr("usage: ./fractol mandelbrot | julia | burningship | ");
		ft_putendl("mandelbar | tapis | buddha");
	}
}

int			main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fractol mandelbrot | julia | burningship | ");
		ft_putendl("mandelbar | tapis | buddha");
	}
	else if (THREAD < 1)
		ft_putendl("Thread can't be less than 1");
	else
		ft_check_arg(av);
	return (0);
}
