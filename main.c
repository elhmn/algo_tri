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

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_tri.h"
#define TEST_SIZE 8
#define RANDMAX 10
#define RANDMIN 0

void	ft_putmap(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("[ %d ] ", tab[i]);
//		if (!(i % 20))
//			printf("\n");
		i++;
	}
	printf("\n");
}

void	settab(int *tab)
{
	int	i;

	i = 0;
	srand(time(NULL));
	while (i < TEST_SIZE)
	{
		*(tab + i) = RANDMIN + rand() % (RANDMAX - RANDMIN);
		i++;
		usleep(100);
	}
}

int		main(void)
{
	int	tab[TEST_SIZE];

	settab(tab);
	printf("Avant le tri :\n");
	ft_putmap(tab, TEST_SIZE);
	tri_fusion(tab, TEST_SIZE);
	printf("Apres le tri :\n");
	ft_putmap(tab, TEST_SIZE);
	return (0);
}
