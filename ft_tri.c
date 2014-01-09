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

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** tri par selection: pour chaque case je verifie
** si elle contien le plus petit element contenu 
** dans la partie du tableau qui la suit de i a n.
*/

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
		i++;
	}
}

/*
** tri par insertion : pour chaque element on
** verifie si il est plus petit le suivant puis
** on s assure qu'il est plus petit que tous les elements qui le precedent et on continue
*/

void	tri_insert(int	*tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i;
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			while (j)
			{
				if (tab[j] < tab[j - 1])
					ft_swap(&tab[j], &tab[j - 1]);
				j--;
			}
		}
		i++;
	}
}

/*
** tri a bulle : Pour chaque element je check si
** il est plus petit que l element suivant puis
** si oui on swap et reitere l op jusqua la fin
** de la liste
*/

void	tri_bulle(int *tab, int size)
{
	int		j;

	while (size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		size--;
	}
}

