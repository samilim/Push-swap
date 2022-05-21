/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 07:40:23 by salimon           #+#    #+#             */
/*   Updated: 2022/05/21 08:10:07 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void    radix_sort(t_datas *datas)
{
    int i;
    int bit_size; //obtenue a partir de l'index

    i = 0;
    /*si 0 push b else ra*/
    while (i < bit_size)
    {
        while (/*stack a pas parcourue entierement*/)
        {
            if (/*index nb*/ >> i == 0)
            {
                ft_pb(datas);
            }
            else
                ft_ra(datas, 1);
        }
    }
}