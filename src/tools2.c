/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:06:39 by jlange            #+#    #+#             */
/*   Updated: 2017/05/24 11:32:29 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_lst(t_coord **alst)
{
	t_coord	*lst;

	while (*alst)
	{
		lst = *alst;
		*alst = (*alst)->next;
		free(lst);
	}
}

void	free_tab_2d(long double **tab)
{
	int i;

	i = 0;
	while (tab && i < WIN_Y)
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}
