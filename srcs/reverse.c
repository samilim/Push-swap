/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/04/15 02:14:09 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* (reverse rotate ): Shift down all elements of the stack by 1.
The last element becomes the first one */

int    ft_rra(t_datas *datas, int rrr)
{
	if (datas->a.head == NULL || datas->a.head->next == NULL)
		return (0);
	push(&datas->a.head, datas->a.last->nb);
	delete_node(&datas->a.last);
	if (!rrr)
		write(1, "rra\n", 4);
	return (0);
}

int    ft_rrb(t_datas *datas, int rrr)
{
	if (datas->b.head == NULL || datas->b.head->next == NULL)
		return (0);
	push(&datas->b.head, datas->b.last->nb);
	delete_node(&datas->b.last);
	if (!rrr)
		write(1, "rrb\n", 4);
	return (0);
}

int		ft_rrr(t_datas *datas)
{
	if ((datas->a.head == NULL || datas->a.head->next == NULL) || (datas->b.head == NULL || datas->b.head->next == NULL))
		return (0);
	ft_rra(datas, 1);
	ft_rrb(datas, 1);
	write(1, "rrr\n", 4);
	return (1);
}