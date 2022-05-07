/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/05/07 10:06:02 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check if the stac is sorted */
int     check_sort(t_stack stack)
{
    t_elem *tmp;
    //int i;

    tmp = stack.head;
    //i = 0;
    while (tmp->next != NULL)
    {
        if (tmp->nb > tmp->next->nb)
            return (0);
        tmp = tmp->next;
    }
    //printf("a is sorted\n");
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
                ft_ra(datas, 1);
        }
    }
    // printf("head a : %lld\n", datas->a.head->nb);
    // printf("last a : %lld\n", datas->a.last->nb);
    // printf("head b : %lld\n", datas->b.head->nb);
    // printf("last b : %lld\n", datas->b.last->nb);
    return (0);
}



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

    pb= 0;
    //printstack(datas);
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


void sort_stack(t_datas *datas)
{
    //printf("\n\n\n\n\n");
    while (datas->b.head != NULL) //tant que stack b pas vide, on trie
    {
        //printstack(datas);
        //head b
        if (datas->b.head->nb < datas->median)
        {
            while (datas->b.head->nb > datas->a.head->nb)
            {
                ft_ra(datas, 1);
                datas->move_count++;
            }
            ft_pa(datas);
            while (datas->move_count-- > 0)
                ft_rra(datas, 1);
        }
        else
        {
            while (datas->b.head->nb < datas->a.last->nb)
            {
                ft_rra(datas, 1);
                datas->move_count++;
            }
            ft_pa(datas);
            //printf ("mc = %d\n", datas->move_count);
            while (datas->move_count > 0)
            {
                ft_ra(datas, 1);
                datas->move_count--;
            }
            ft_ra(datas, 1);
        }
        datas->move_count = 0;
        //last b
    }    
}


/*
    Push all nb in the stack b except min max and median
*/
void    push_to_b(t_datas *datas)
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
                ft_ra(datas, 1);
        }
    }
    sort_three(datas);
    sort_stack(datas);
    // printf("head a : %lld\n", datas->a.head->nb);
    // printf("last a : %lld\n", datas->a.last->nb);
    // printf("head b : %lld\n", datas->b.head->nb);
    // printf("last b : %lld\n", datas->b.last->nb);
}

/* Obtain tab of the sorted arguments */
int    sort_tab(t_datas *datas)
{
    int i;
    int sorted;
    long long int swp;

    i = 1;
    sorted = 0;
    while(i < datas->nb_elem)
    {
        if (datas->tab[i] < datas->tab[i - 1])
        {
            swp = datas->tab[i];
            datas->tab[i] = datas->tab[i - 1];
            datas->tab[i - 1] = swp;
            sorted = 1;
            if (i == datas->nb_elem / 2)
                datas->median = datas->tab[i];
            i = 0;
        }
        i++;
    }
    datas->min = datas->tab[0];
    datas->max = datas->tab[datas->nb_elem - 1];
    i = 0;
    // printf("arg sort : ");
    // while (i < datas->nb_elem)
    // {
    //     printf("%lld ", datas->tab[i]);
    //     i++;
    // }
    // printf("\n");
    return (sorted);
}

void	push_swap(t_datas *datas)
{
    //int i;

    //i = 0;
    //printf("nb arg = %d\n", datas->nb_elem);


    sort_tab(datas/*, &datas->a*/);


    // printf("mediane = %lld\n", datas->median);
    // printf("MIN : %lld\n", datas->min);
    // printf("MAX : %lld\n\n", datas->max);
    //push_up_to_median(datas);
    // printf("head = %lld\n", datas->a.head->nb);
    // printf("next = %lld\n", datas->a.head->next->nb);
    // printf("last = %lld\n", datas->a.last->nb);
    if (datas->nb_elem == 3)
        sort_three(datas);
    if (datas->nb_elem == 5 && !check_sort(datas->a)/*sort_tab(datas)*/) /* 3 4 5 1 2 */
        sort_five(datas);
    if (!check_sort(datas->a))
        push_to_b(datas);
}