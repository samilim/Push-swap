/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 07:40:23 by salimon           #+#    #+#             */
/*   Updated: 2022/05/22 04:12:02 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/* 
** Replicate stack a in a tab and save their index
*/
// void get_indexes(t_datas *datas)
// {
// 	int i;
// 	long long int swp;

// 	i = 1;
// 	while (i < datas->nb_elem)
// 	{
// 		if (datas->tab[i] < datas->tab[i - 1])
// 		{
// 			swp = datas->tab[i];
// 			datas->tab[i] = datas->tab[i - 1];
// 			datas->tab[i - 1] = swp;
// 			if (i == datas->nb_elem / 2)
// 				datas->median = datas->tab[i];
// 			i = 0;
// 		}
// 		i++;
// 	}
// 	//datas->min = datas->tab[0];
// 	//datas->max = datas->tab[datas->nb_elem - 1];
// 	i = 0;
// 	// printf("arg sort : ");
// 	// while (i < datas->nb_elem)
// 	// {
// 	//     printf("%lld ", datas->tab[i]);
// 	//     i++;
// 	// }
// 	// printf("\n");
// }

int get_index(t_datas *datas, long long element)
{
	int i;

	i = 0;
	while (i < datas->nb_elem)
	{
		if (datas->tab[i] == element)
			return (i);
		i++;
	}
    return (i);
}

// 8 elem
// 2 6 8 9 5 1 3 7
void    radix_sort(t_datas *datas)
{
    int i;
    int j;
    int bit_size; //obtenue a partir de l'index ou de la taille de la stack?
    int max_index;

    i = 0;
    bit_size = 0;
    max_index = datas->nb_elem - 1;
    //printf("max_index = %d\n", max_index);
    while ((max_index >> bit_size) != 0)
        bit_size++;
    //printf("bit size = %d\n", bit_size);
    /*si 0 push b else ra*/
    while (i < bit_size)
    {
        j = 1;
        while (j <= datas->nb_elem)
        {
            if (((get_index(datas, datas->a.head->nb) >> i)&1) == 0)
            {
                ft_pb(datas);
            }
            else
                ft_ra(datas, 1);
            j++;
        }
        while (datas->b.head != NULL)
        {
            ft_pa(datas);
        }
        i++;
    }
}