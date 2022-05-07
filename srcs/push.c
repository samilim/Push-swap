/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:57:16 by salimon           #+#    #+#             */
/*   Updated: 2022/05/07 10:44:24 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty */

void	ft_pa(t_datas *datas)
{
	if (datas->b.head == NULL)
		return ;
	if (datas->a.head == NULL)
	{
		if (!append(&datas->a.head, &datas->a.last, datas->b.head->nb))
			error_case(datas, 4);
	}
	else
	{
		if (!push(&datas->a.head, datas->b.head->nb))
			error_case(datas, 4);
	}
	datas->a.size += 1;
	datas->b.size -= 1;
	delete_node(&datas->b.head);
	write(1, "pa\n", 3);
}

/* Same but reversed */

void	ft_pb(t_datas *datas)
{
	if (datas->a.head == NULL)
		return ;
	if (datas->b.head == NULL)
	{
		//printf("append b\n");
		if (!append(&datas->b.head, &datas->b.last, datas->a.head->nb))
			error_case(datas, 4);
	}
	else
	{
		//printf("push b\n");
		if (!push(&datas->b.head, datas->a.head->nb))
			error_case(datas, 4);
	}
	datas->a.size -= 1;
	datas->b.size += 1;
	//printf("head b : %lld\n", datas->b.head->nb);
    //printf("last b : %lld\n", datas->b.last->nb);
	delete_node(&datas->a.head);
	write(1, "pb\n", 3);
}
