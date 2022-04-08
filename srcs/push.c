/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:57:16 by salimon           #+#    #+#             */
/*   Updated: 2022/04/08 20:43:10 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// bullshit, ne pas lire merci

void	ft_pa(t_datas *datas)
{
	datas->a.last = datas->b.last;
	datas->b.last->next = 0;
	write(1, "pa\n", 4);
}

void	ft_pb(t_datas *datas)
{
	append(datas, &datas->b.head, &datas->b.last, );
	datas->b.last = datas->a.last;
	datas->a.last->next = 0;
	write(1, "pb\n", 4);
}
