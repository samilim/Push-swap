/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/04/17 17:48:39 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check if the stac is sorted */
int     check_sort(t_stack *stack)
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
    printf("good\n");
    return (1);
}

/*
    Push all nb < to the median in the stack b
*/
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
            if (datas->b.head != NULL && datas->b.head->next != NULL)
            {
                if (datas->b.head->nb < datas->b.last->nb)
                    ft_rr(datas);
            }
            ft_ra(datas, 0);
        }
    }
    // printf("head a : %lld\n", datas->a.head->nb);
    // printf("last a : %lld\n", datas->a.last->nb);
    // printf("head b : %lld\n", datas->b.head->nb);
    // printf("last b : %lld\n", datas->b.last->nb);
    return (0);
}

/* Obtain tab of the sorted arguments */
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
    //printf("arg sort : ");
    while (i < datas->nb_elem)
    {
        //printf("%lld ", datas->tab[i]);
        i++;
    }
    //printf("\n");
}

int	push_swap(t_datas *datas)
{
    //int i = 0;
    //int j = 0;
    //printf("nb arg = %d\n", datas->nb_elem);
    sort_tab(datas, &datas->a);
    //printf("mediane de a = %lld\n", datas->a.mediane);
    push_up_to_b(datas);
    // while (i < datas->nb_elem)
    // {
    //     while(j < datas->nb_elem)
    //     {
    //         if (datas->b.head == NULL || (datas->a.head->nb > datas->b.head->nb))
    //         {
    //             ft_pb(datas);
    //             j++;
    //         }
    //         if (datas->b.head->nb < datas->b.last->nb)
    //         {
    //             if (datas->a.head->nb > datas->a.last->nb)
    //                 ft_rrr(datas);
    //             else
    //                 ft_rrb(datas, 0);
    //         }
    //         else
    //             ft_ra(datas, 0);
    //     }
    //     ft_pa(datas);
    //     i++;
    // }
    return (0);
}