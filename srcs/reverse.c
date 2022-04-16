/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/04/16 02:54:14 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* (reverse rotate ): Shift down all elements of the stack by 1.
The last element becomes the first one */

int	ft_rra(t_datas *datas, int rrr)
{
	t_elem	*tmp;

	if (datas->a.head == NULL || datas->a.head->next == NULL)
		return (0);
	push(&datas->a.head, datas->a.last->nb);
	tmp = datas->a.last->prev;
	delete_node(&datas->a.last);
	datas->a.last = tmp;
	datas->a.last->next = NULL;
	if (!rrr)
		write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_datas *datas, int rrr)
{
	t_elem	*tmp;

	if (datas->b.head == NULL || datas->b.head->next == NULL)
		return (0);
	push(&datas->b.head, datas->b.last->nb);
	tmp = datas->b.last->prev;
	delete_node(&datas->b.last);
	datas->b.last = tmp;
	datas->b.last->next = NULL;
	if (!rrr)
		write(1, "rrb\n", 4);
	return (0);
}

int	ft_rrr(t_datas *datas)
{
	if ((datas->a.head == NULL || datas->a.head->next == NULL)
		|| (datas->b.head == NULL || datas->b.head->next == NULL))
		return (0);
	ft_rra(datas, 1);
	ft_rrb(datas, 1);
	write(1, "rrr\n", 4);
	return (1);
}
