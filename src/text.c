/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:00:29 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 12:29:27 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void		ft_text3(float nb, char **str)
{
	char *tmp;
	char *tmp2;

	while (nb)
	{
		nb *= 10;
		tmp = *str;
		tmp2 = ft_itoa(nb);
		*str = ft_strjoin(tmp, tmp2);
		nb = nb - (int)nb;
		free(tmp);
		free(tmp2);
	}
}

static inline void		ft_text2(t_mlx *mlx)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	float	nb;

	str = ft_strdup("Zoom / ");
	tmp = str;
	tmp2 = ft_itoa(mlx->h);
	str = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	nb = mlx->h - (int)mlx->h;
	if (nb)
	{
		tmp = str;
		str = ft_strjoin(tmp, ",");
		free(tmp);
	}
	ft_text3(nb, &str);
	mlx_string_put(mlx->mlx, mlx->win, 2, 15, 0x00FFFFFF, str);
	free(str);
}

static inline char		*ft_name(int opt)
{
	char *name;

	if (opt == 1)
		name = ft_strdup("Mandelbrot");
	else if (opt == 2)
		name = ft_strdup("Julia");
	else if (opt == 3)
		name = ft_strdup("Burning ship");
	else if (opt == 4)
		name = ft_strdup("Mandelbar");
	else if (opt == 5)
		name = ft_strdup("Tapis de Sierpinski");
	else if (opt == 6)
		name = ft_strdup("Buddhabrot");
	else
		name = ft_strdup("Unknow");
	return (name);
}

void					ft_text(t_mlx *mlx)
{
	char	*str;
	char	*tmp;
	char	*name;
	char	*nb;

	name = ft_name(mlx->opt);
	str = ft_strdup("Iterations: ");
	tmp = str;
	nb = ft_itoa(mlx->iter);
	str = ft_strjoin(tmp, nb);
	free(tmp);
	free(nb);
	mlx_string_put(mlx->mlx, mlx->win, 2, 2, 0x00FFFFFF, str);
	mlx_string_put(mlx->mlx, mlx->win, WIN_X - (ft_strlen(name) * 10 + 2), 2,
			0x00FFFFFF, name);
	free(str);
	free(name);
	ft_text2(mlx);
}
