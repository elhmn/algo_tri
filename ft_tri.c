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
#include <stdlib.h>
#include <stdio.h>

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
		if (tab[i] > tab[i + 1] && i + 1 != size)
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

/*
** tri par fusion : ici on scinde la liste en
** deux sous liste a trier puis on les qu on
** fusionne
*/

//Penser a le faire fonctionner pour les tableaux de taille impaire

void	set_fusion(int *tab, int *tab1, int *tab2, int size)
{
	int		i;
	int		j;
	int		*tmp;

	tmp = tab;
	i = 0;
	j = 0;
	while (j < size / 2 && i < size / 2)//(((j < size / 2 && size % 2) 
			//	||(j < size / 2 + 1 && !(size % 2))))
	{
		if (tab1[i] < tab2[j])
			*tab++ = tab1[i++];
		else
			*tab++ = tab2[j++];
		ft_putmap(tmp, size);
	}
	printf("****************************\n");
	if (j == size / 2)
	{
		while (i < size / 2)
		{
			*tab++ = tab1[i++];
			ft_putmap(tmp, size);
		}
	}
	else if (i == size / 2)
	{
		while (j < size / 2)
		{
			*tab++ = tab2[j++];
			ft_putmap(tmp, size);
		}
	}
}

void	set_fus_tab(int *tab, int *tab1, int pos, int size)
{
	int		i;

	i = 0;
	while (pos < size)
		tab1[i++] = tab[pos++];
}

void	tri_fusion_aux(int *tab, int size, int stat)
{
	int		*tab1;
	int		*tab2;

	tab1 = malloc(sizeof(int) * size);
	set_fus_tab(tab, tab1, 0, size * 2);
	//printf("Avant tab1 :\n");
	//ft_putmap(tab1, size);
	tri_insert(tab1, size);
	printf("Apres tab1 :\n");
	ft_putmap(tab1, size);
	if (!stat)
	{
		tab2 = malloc(sizeof(int) * size);
		set_fus_tab(tab, tab2, size, (size * 2));
		//printf("Avant tab2 :\n");
	//	ft_putmap(tab2, size);
		tri_insert(tab2, size);
		printf("Apres tab2 :\n");
		ft_putmap(tab2, size);
		set_fusion(tab, tab1, tab2, size * 2);
	}
	else
	{
		tab2 = malloc(sizeof(int) * (size + 1));
		set_fus_tab(tab, tab2, size, (size * 2) + 1);
	//	printf("Avant tab2 :\n");
	//	ft_putmap(tab2, size + 1);
		tri_insert(tab2, size + 1);
		printf("Apres tab2 :\n");
		ft_putmap(tab2, size + 1);
		set_fusion(tab, tab1, tab2, (size * 2) + 1);
	}
}

void	tri_fusion(int *tab, int size)
{
	if (size % 2)
		tri_fusion_aux(tab, size / 2, 1);
	else
		tri_fusion_aux(tab, size / 2, 0);
}

