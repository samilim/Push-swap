/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:57:16 by salimon           #+#    #+#             */
/*   Updated: 2022/04/15 23:27:19 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty */

int	ft_pa(t_datas *datas)
{
	if (datas->b.head == NULL)
		return (0);
	if (datas->a.head == NULL)
	{
		if (!append(&datas->a.head, &datas->a.last, datas->b.head->nb))
			return (4);
	}
	else
	{
		if (!push(&datas->a.head, datas->b.head->nb))
			return (4);
	}
	delete_node(&datas->b.head);
	write(1, "pa\n", 4);
	return (0);
}

/* Same but reversed */

int	ft_pb(t_datas *datas)
{
	if (datas->a.head == NULL)
		return (0);
	if (datas->b.head == NULL)
	{
		if (!append(&datas->b.head, &datas->b.last, datas->a.head->nb))
			return (4);
	}
	else
	{
		if (!push(&datas->b.head, datas->a.head->nb))
			return (4);
	}
	delete_node(&datas->a.head);
	write(1, "pb\n", 4);
	return (0);
}
