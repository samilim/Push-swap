/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 05:37:37 by user42            #+#    #+#             */
/*   Updated: 2022/04/15 23:25:20 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift up all elements of the stack by 1.
The first element becomes the last one. */

int	ft_ra(t_datas *datas, int rr)
{
	if (datas->a.head == NULL || datas->a.head->next == NULL)
		return (0);
	append(&datas->a.head, &datas->a.last, datas->a.head->nb);
	delete_node(&datas->a.head);
	if (!rr)
		write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(t_datas *datas, int rr)
{
	if (datas->b.head == NULL || datas->b.head->next == NULL)
		return (0);
	append(&datas->b.head, &datas->b.last, datas->b.head->nb);
	delete_node(&datas->b.head);
	if (!rr)
		write(1, "rb\n", 3);
	return (0);
}

int	ft_rr(t_datas *datas)
{
	if ((datas->a.head == NULL || datas->a.head->next == NULL)
		|| (datas->b.head == NULL || datas->b.head->next == NULL))
		return (0);
	ft_ra(datas, 1);
	ft_rb(datas, 1);
	write(1, "rr\n", 3);
	return (1);
}
