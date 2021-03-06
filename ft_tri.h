/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 10:06:28 by elhmn             #+#    #+#             */
/*   Updated: 2014/01/09 10:06:28 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRI_H
#define FT_TRI_H

void	tri_select(int *tab, int size);
void	ft_putmap(int *tab, int size);
void	tri_insert(int	*tab, int size);
void	tri_bulle(int *tab, int size);
void	tri_fusion_aux(int *tab, int size, int stat);
void	tri_fusion(int *tab, int size);

#endif
