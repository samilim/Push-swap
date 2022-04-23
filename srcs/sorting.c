/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/04/23 23:40:22 by salimon          ###   ########.fr       */
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
    return (1);
}


void    get_median(t_stack *stack)
{
    t_stack *tmp;
    long long int swp;

    tmp = stack;
    // while (tmp.next != NULL)
    // {
    //     if (tmp.next != NULL && tmp.nb > tmp.next->nb)
    //     {
    //         swp = tmp.nb;
    //         tmp.nb = tmp.next->nb;
    //         tmp.next->nb = swp;
    //         while (tmp.prev != NULL)
    //             tmp = *tmp.prev;
    //     }
    //     tmp = *tmp.next;
    // }
    while (tmp->head->next != NULL)
    {
        if (tmp->head->next != NULL && tmp->head->nb > tmp->head->next->nb)
        {
            swp = tmp->head->nb;
            tmp->head->nb = tmp->head->next->nb;
            tmp->head->next->nb = swp;
            while (tmp->head->prev != NULL)
                tmp->head = tmp->head->prev;
        }
        tmp->head = tmp->head->next;
    }
    // while (tmp.next != NULL)
    // {
    //     if (tmp.next != NULL && tmp.nb > tmp.next->nb)
    //     {
    //         swp = tmp.nb;
    //         tmp.nb = tmp.next->nb;
    //         tmp.next->nb = swp;
    //         while (tmp.prev != NULL)
    //             tmp = tmp.prev;
    //     }
    //     tmp = tmp.next;
    // }
    // while (tmp->head->prev != NULL)
    //             tmp->head = tmp->head->prev;
    // t_elem *tmp2;

	// tmp2 = tmp->head;
    // printf("\na in forward direction (top to bottom of the list)\n");
    // while (tmp2 != NULL) {
    //     printf("%lld ", tmp2->nb);
    //     //datas->a.last = tmp;
    //     tmp2 = tmp2->next;
    // }
}

/*
    Push all nb < to the median in the stack b
*/
int    push_up_to_median(t_datas *datas)
{
    int i = 0;
    while (i < (datas->nb_elem / 2 - 3) && (datas->a.head != NULL && datas->a.head->next != NULL))
    {
        //get_median(&datas->a);
        if (datas->a.head->nb < datas->median) //recalculer la mediane a chaque cycle?
        {
            ft_pb(datas);
            i++;
        }
        else
        {
            if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
            {
                    ft_rr(datas);
            }
            else
                ft_ra(datas, 0);
        }
    }
    // printf("head a : %lld\n", datas->a.head->nb);
    // printf("last a : %lld\n", datas->a.last->nb);
    // printf("head b : %lld\n", datas->b.head->nb);
    // printf("last b : %lld\n", datas->b.last->nb);
    return (0);
}


/*
    Push all nb in the stack b except min max and median
*/
int    push_to_b(t_datas *datas)
{
    int i = 0;
    while (i < (datas->nb_elem - 3))
    {
        if (datas->a.head->nb != datas->median && datas->a.head->nb != datas->min && datas->a.head->nb != datas->max)
        {
            ft_pb(datas);
            i++;
        }
        else
        {
            if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb) //??
            {
                    ft_rr(datas);
            }
            else
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
void    sort_tab(t_datas *datas)
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
                datas->median = datas->tab[i];
            i = 0;
        }
        i++;
    }
    datas->min = datas->tab[0];
    datas->max = datas->tab[datas->nb_elem - 1];
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
    //printf("nb arg = %d\n", datas->nb_elem);
    sort_tab(datas/*, &datas->a*/);
    printf("mediane = %lld\n", datas->median);
    printf("MIN : %lld\n", datas->min);
    printf("MAX : %lld\n", datas->max);
    //push_up_to_median(datas);
    push_to_b(datas);

    // if (datas->nb_elem == 3)
    // {
    //     if (datas->a.head->nb > datas->a.last->nb)
    //     {
    //         if(datas->a.head->nb > datas->a.head->next->nb)
    //         {

    //         }
    //         else
                
    //     }
    // }

    // if (datas->nb_elem == 5)
    // {
    //     /**/
    // }


    return (0);
}