/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:03 by user42            #+#    #+#             */
/*   Updated: 2022/03/24 08:17:02 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//vieux bullshit ne pas lire

void	ft_sa()
{
	write(1, "sa\n", 3);
}

void	ft_sb()
{
	write(1, "sb\n", 3);
}

void	ft_ss()
{
	if ((*a && (*a)->next) && (*b && (*b)->next)) //chck ici?
	{
		ft_sa(a);
		ft_sb(b);
		write(1, "ss\n", 3);
	}
}