/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:03:52 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 13:25:47 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_rgb3(int *nb, int opt, int tmp)
{
	if (opt == 9)
	{
		*nb += tmp << 21;
		*nb += tmp << 13;
		*nb &= 0x00FFFFFF;
	}
	else if (opt == 10)
	{
		*nb += *nb << 1;
		*nb += tmp << 7;
		*nb += tmp << 8;
		*nb += tmp << 24;
		*nb += tmp << 18;
		*nb += tmp << 14;
	}
}

static inline void	ft_rgb2(int *nb, int opt, int tmp)
{
	if (opt == 6)
	{
		*nb += *nb << 9;
		*nb += tmp << 19;
	}
	else if (opt == 7)
	{
		*nb += *nb << 8;
		*nb += tmp << 18;
	}
	else if (opt == 8)
	{
		*nb += *nb << 1;
		*nb += tmp << 11;
		*nb += tmp << 18;
	}
	else
		ft_rgb3(nb, opt, tmp);
}

int					ft_rgb(int nb, int opt)
{
	int tmp;

	while (nb & 0xFFFFFF00)
		nb = nb >> 1;
	if (opt < 4 && opt != 1)
	{
		while (opt > 1)
		{
			nb = nb << 8;
			--opt;
		}
	}
	tmp = nb;
	if (opt == 4)
	{
		nb += nb << 8;
		nb += tmp << 16;
	}
	else if (opt == 5)
		nb += tmp << 8;
	else
		ft_rgb2(&nb, opt, tmp);
	return (nb);
}

int					ft_b(int nb, int opt)
{
	int tmp;

	nb *= nb / 2;
	while (nb & 0xFFFFFF00)
		nb = nb >> 1;
	tmp = nb;
	if (opt % 2)
	{
		nb += nb << 9;
		nb += tmp << 19;
	}
	else
	{
		nb *= nb;
		nb += tmp << 18;
	}
	return (nb);
}
