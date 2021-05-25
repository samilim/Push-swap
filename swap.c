/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:03 by user42            #+#    #+#             */
/*   Updated: 2021/05/25 05:07:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	ft_sa(t_stack_a **a)
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

void	ft_sb(t_stack_a **b)
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

void	ft_ss(t_stack_a **a, t_stack_b **b)
{
	if ((*a && (*a)->next) && (*b && (*b)->next)) //chck ici?
	{
		ft_sa(a);
		ft_sb(b);
		write(1, "ss\n", 3);
	}
}