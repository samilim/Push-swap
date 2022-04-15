/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:03 by user42            #+#    #+#             */
/*   Updated: 2022/04/15 00:51:43 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements */

int	ft_sa(t_datas *datas, int ss)
{
	long long int swap;

	if (datas->a.head == NULL || datas->a.head->next == NULL)
		return (0);
	swap = datas->a.head->nb;
	datas->a.head->nb = datas->a.head->next->nb;
	datas->a.head->next->nb = swap;
	if (!ss)
		write(1, "sa\n", 4);
	return (1);
}

int	ft_sb(t_datas *datas, int ss)
{
	long long int swap;

	if (datas->b.head == NULL || datas->b.head->next == NULL)
		return (0);
	swap = datas->b.head->nb;
	datas->b.head->nb = datas->b.head->next->nb;
	datas->b.head->next->nb = swap;
	if (!ss)
		write(1, "sb\n", 4);
	return (1);
}

/* sa and sb at the same time */

int	ft_ss(t_datas *datas)
{
	if ((datas->a.head == NULL || datas->a.head->next == NULL) || (datas->b.head == NULL || datas->b.head->next == NULL))
		return (0);
	ft_sa(datas, 1);
	ft_sb(datas, 1);
	write(1, "ss\n", 3);
	return (1);
}