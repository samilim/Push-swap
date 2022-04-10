/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:03 by user42            #+#    #+#             */
/*   Updated: 2022/04/10 22:17:21 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements */

int	ft_sa(t_datas *datas)
{
	if (!push(&datas->a.head, datas->b.head->nb))
		return (4);
	delete_node(&datas->b.head);
	write(1, "sa\n", 4);
	return (0);
}

int	ft_sb(t_datas *datas)
{
	if (datas->b.head == NULL)
	{
		if (!append(datas, &datas->b.head, &datas->b.last, datas->a.head->nb))
			return (4);
	}
	else
	{
		if (!push(&datas->b.head, datas->a.head->nb))
			return (4);
	}
	delete_node(&datas->a.head);
	if (/*pas ss*/)
		write(1, "sb\n", 4);
	return (0);
}

/* sa and sb at the same time */

int	ft_ss()
{
	ft_sa();
	ft_sb();
	write(1, "ss\n", 3);
}