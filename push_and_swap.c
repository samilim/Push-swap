/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:57:16 by salimon           #+#    #+#             */
/*   Updated: 2021/05/23 05:34:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	ft_pa(t_pile_a **a, t_pile_b **b)
{
	if (*b)
		*a = *b;
	write(1, "pa\n", 3);
}

void	ft_pb(t_pile_a **a, t_pile_b **b)
{
    if (*a)
        *b = *a;
	write(1, "pb\n", 3);
}

void	ft_sa(t_pile_a **a)
{
	int	tmp;

	tmp = *a;
	if (*a && (*a)->next)
	{
		*a = (*a)->next;
		(*a)->next = tmp;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_pile_a **b)
{
	int	tmp;

	tmp = *b;
	if (*b && (*b)->next)
	{
		*b = (*b)->next;
		(*b)->next = tmp;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_pile_a **a, t_pile_b **b)
{
	if ((*a && (*a)->next) && (*b && (*b)->next)) //chck ici?
	{
		ft_sa(a);
		ft_sb(b);
		write(1, "ss\n", 3);
	}
}