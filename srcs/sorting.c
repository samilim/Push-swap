/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/04/16 08:51:42 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*push b le plus petit nb puis adapter à partir de là
** grps de 3
**diviser par deux
**ecart min et max
opti en essayant d'utiliser tous les moves*/

int     check_sort(/*t_datas *datas, */t_stack *stack)
{
    t_elem *tmp;
    //int i;

    tmp = stack->head;
    //i = 0;
    while (tmp->next != NULL)
    {
        if (tmp->nb > tmp->next->nb)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int    push_up_to_b(t_datas *datas)
{
    int i = 0;
    while (i < datas->nb_elem / 2 && (datas->a.head != NULL && datas->a.head->next != NULL))
    {
        if (datas->a.head->nb < datas->a.mediane)
        {
            ft_pb(datas);
            i++;
        }
        else
        {
            if (datas->b.head != NULL)
            {
                if (datas->b.head->nb < datas->b.last->nb)
                    ft_rr(datas);
            }
            ft_ra(datas, 1);
        }
    }
    return (0);
}

void    sort_tab(t_datas *datas, t_stack *stack)
{
    int i;
    long long int swp;

    i = 1;
    while(i < datas->nb_elem)
    {
        if (datas->tab[i] < datas->tab[i - 1])
        {
            swp = datas->tab[i];
            datas->tab[i] = datas->tab[i - 1];
            datas->tab[i - 1] = swp;
            if (i == datas->nb_elem / 2)
                stack->mediane = datas->tab[i];
            i = 0;
        }
        i++;
    }
    i = 0;
    printf("arg sort : ");
    while (i < datas->nb_elem)
    {
        printf("%lld ", datas->tab[i]);
        i++;
    }
    printf("\n");
}

int	push_swap(t_datas *datas)
{
    printf("nb arg = %d\n", datas->nb_elem);
    sort_tab(datas, &datas->a);
    printf("mediane de a = %lld\n", datas->a.mediane);
    push_up_to_b(datas);
    // while (!check_sort(datas, &datas->a))
    // {

    // }
    //get_index();
    return (0);
}