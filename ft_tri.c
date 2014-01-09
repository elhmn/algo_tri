/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 10:06:18 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/09 10:06:18 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tri.h"

/*
** tri par selection
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	tri_select(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		ft_putmap(tab);
		i++;
	}
}
