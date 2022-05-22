/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 05:32:55 by salimon           #+#    #+#             */
/*   Updated: 2022/05/22 04:18:59 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void sort_three(t_datas *datas)
{
	while (!(datas->a.head->nb < datas->a.head->next->nb && datas->a.head->next->nb < datas->a.last->nb))
	{
		if (datas->a.head->nb > datas->a.last->nb && datas->a.last->nb < datas->a.head->next->nb && datas->a.head->nb < datas->a.head->next->nb)
		{
			if (datas->b.head != NULL && datas->b.head->next != NULL && (datas->b.head->nb < datas->b.head->next->nb))
				ft_rrr(datas);
			else
				ft_rra(datas, 1);
		}
		else if (datas->a.head->nb > datas->a.head->next->nb && datas->a.head->next->nb < datas->a.last->nb && datas->a.head->nb > datas->a.last->nb)
		{
			if (datas->b.head != NULL && datas->b.head->next != NULL && (datas->b.head->nb < datas->b.head->next->nb))
				ft_rr(datas);
			else
				ft_ra(datas, 1);
		}
		else
		{
			if (datas->b.head != NULL && datas->b.head->next != NULL && (datas->b.head->nb < datas->b.head->next->nb))
				ft_ss(datas);
			else
				ft_sa(datas, 1);
		}
	}
}

void sort_five(t_datas *datas)
{
	int pb;

	pb = 0;
	while (pb < 2)
	{
		if (datas->a.last->nb == datas->min || datas->a.last->nb == datas->tab[1])
		{
			ft_rra(datas, 1);
			ft_pb(datas);
			pb++;
		}
		else if (datas->a.head->nb == datas->min || datas->a.head->nb == datas->tab[1])
		{
			ft_pb(datas);
			pb++;
		}
		else
			ft_ra(datas, 1);
	}
	sort_three(datas);
	ft_pa(datas);
	ft_pa(datas);
	if (datas->a.head->nb > datas->a.head->next->nb)
		ft_sa(datas, 1);
}