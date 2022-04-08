/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 20:33:27 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*push b le plus petit nb puis adapter à partir de là
** grps de 3
**diviser par deux
**ecart min et max
opti en essayant d'utiliser tous les moves*/

void	push_swap(t_datas *datas)
{
    append(datas, &datas->b.head, &datas->b.last, 3);
    ft_pb(datas);
    //ft_pa(datas);
}