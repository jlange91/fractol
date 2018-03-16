/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:56:39 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 13:40:30 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ZOOM 12
# define DEZOOM 14
# define PLUS 27
# define MINUS 24
# define COLOR 8
# define MUL_COLOR1 6
# define MUL_COLOR2 7
# define WIN_X 800
# define WIN_Y 600
# define THREAD 8
# define ITER 100

typedef struct		s_remap
{
	long double in_min;
	long double in_max;
	long double out_min;
	long double out_max;
}					t_remap;

typedef struct		s_calc
{
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	int			i;
}					t_calc;

typedef struct		s_ens
{
	long double x1;
	long double y1;
	long double x2;
	long double y2;
}					t_ens;

typedef struct		s_mlx
{
	void				(*tab[6])(struct s_mlx *mlx);
	void				*mlx;
	void				*win;
	void				*mlx_img;
	char				*str_img;
	unsigned int		*img;
	int					iter;
	t_ens				ens1;
	t_ens				save;
	int					color;
	long double			c_r;
	long double			c_i;
	long double			xu;
	long double			yu;
	long double			h;
	int					opt;
	int					test;
	bool				julia;
	int					i;
}					t_mlx;

typedef struct		s_frac
{
	t_mlx			*mlx;
	double			min;
	double			max;
	long double		zoom_x;
	long double		zoom_y;
	double			x;
	int				y;
	long double		**tab;
}					t_frac;

typedef struct		s_thrd
{
	int			i;
	pthread_t	t;
	t_mlx		*mlx;
}					t_thrd;

typedef struct		s_coord
{
	long double		x;
	long double		y;
	struct s_coord	*next;
}					t_coord;

void				ft_lst_add(t_coord **begin, long double x, long double y);
void				ft_display_img(t_mlx *mlx, int zoom);
long double			ft_remap2(int x, t_remap info);
int					ft_display_hook(int keycode, t_mlx *mlx);
int					ft_redcross(void *lol);
void				ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void				ft_fractol();
int					ft_rgb(int nb, int opt);
void				ft_julia(t_mlx *mlx);
void				ft_mandelbrot(t_mlx *mlx);
void				ft_tapis(t_mlx *mlx);
void				ft_mandelbar(t_mlx *mlx);
void				ft_burningship(t_mlx *mlx);
void				ft_buddha(t_mlx *mlx);
void				ft_color(t_mlx *mlx, int x, int y, int iter);
void				init_mandelbar(t_mlx *mlx);
void				init_mandelbrot(t_mlx *mlx);
void				init_tapis(t_mlx *mlx);
void				init_julia(t_mlx *mlx);
void				init_burningship(t_mlx *mlx);
void				init_buddha(t_mlx *mlx);
void				ft_tmp(t_mlx *mlx);
void				ft_text(t_mlx *mlx);
void				ft_zoom(t_mlx *mlx);
void				ft_dezoom(t_mlx *mlx);
int					ft_mouse_click(int but, int x, int y, t_mlx *mlx);
int					ft_mouse_moove(int x, int y, t_mlx *mlx);
void				ft_calc_power(t_calc *c, long double tmp, int opt);
void				ft_calc_power2(t_calc *c, long double tmp, int opt);
void				free_lst(t_coord **begin);
void				free_tab_2d(long double **tab);
int					ft_b(int nb, int opt);

#endif
