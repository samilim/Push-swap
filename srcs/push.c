/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:57:16 by salimon           #+#    #+#             */
/*   Updated: 2022/04/10 22:04:30 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// bullshit, ne pas lire merci

int	ft_pa(t_datas *datas)
{
	if (!push(&datas->a.head, datas->b.head->nb))
		return (4);
	delete_node(&datas->b.head);
	write(1, "pa\n", 4);
	return (0);
}

int	ft_pb(t_datas *datas)
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
	write(1, "pb\n", 4);
	return (0);
}
