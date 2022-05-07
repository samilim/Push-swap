/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:03 by user42            #+#    #+#             */
/*   Updated: 2022/05/07 10:45:13 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements */

void	ft_sa(t_datas *datas, int print)
{
	long long int	swap;

	if (datas->a.head == NULL || datas->a.head->next == NULL)
		return ;
	swap = datas->a.head->nb;
	datas->a.head->nb = datas->a.head->next->nb;
	datas->a.head->next->nb = swap;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_datas *datas, int print)
{
	long long int	swap;

	if (datas->b.head == NULL || datas->b.head->next == NULL)
		return ;
	swap = datas->b.head->nb;
	datas->b.head->nb = datas->b.head->next->nb;
	datas->b.head->next->nb = swap;
	if (print)
		write(1, "sb\n", 3);
}

/* sa and sb at the same time */

void	ft_ss(t_datas *datas)
{
	if ((datas->a.head == NULL || datas->a.head->next == NULL)
		|| (datas->b.head == NULL || datas->b.head->next == NULL))
		return ;
	ft_sa(datas, 0);
	ft_sb(datas, 0);
	write(1, "ss\n", 3);
}
