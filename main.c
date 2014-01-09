/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 10:05:57 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/09 10:05:57 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "ft_tri.h"

void	ft_putmap(int *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("[ %d ] ", tab[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	int		tab[10] = {0, 3, 4, 87, 7, 4, -3, 6, -8};
	printf("Avant le tri :\n");
	ft_putmap(tab);
	printf("Apres le tri :\n");
	tri_select(tab, 10);
	ft_putmap(tab);
	return (0);
}
