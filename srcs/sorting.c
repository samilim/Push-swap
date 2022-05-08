/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/05/08 04:57:03 by salimon          ###   ########.fr       */
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

void inferior_to_median(t_datas *datas)
{
	if (datas->b.head->nb < datas->median)
	{
		while (datas->b.head->nb > datas->a.head->nb)
		{
			if (datas->b.head->nb < datas->b.last->nb)
				ft_rr(datas);
			else
				ft_ra(datas, 1);
			datas->move_count++;
		}
		ft_pa(datas);
		while (datas->b.head != NULL && datas->b.head->nb < datas->median && datas->b.head->nb < datas->a.head->nb && datas->b.head->nb > datas->a.last->nb)
			ft_pa(datas);
		// atas->move_count++;
	}
	while (datas->move_count-- > 0)
	{
		// if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
		//     ft_rrr(datas);
		// else
		ft_rra(datas, 1);
	}
	datas->move_count = 0;
}

long long int *stack_to_tab(t_stack a, int size)
{
	int i;
	long long int	*tab;
	t_stack tmp;

	i = 0;
	tmp = a;
	tab = malloc(sizeof(long long int) * size);
	while (i < size)
	{
		tab[i] = tmp.head->nb;
		tmp.head = tmp.head->next;
		i++;
	}
	return (tab);
}

void best_move(t_datas *datas)
{
	long long int *actual_a;

	actual_a = stack_to_tab(datas->a, datas->a.size);
	free (actual_a);
}

void superior_to_median(t_datas *datas)
{
	while (datas->b.head->nb < datas->a.last->nb)
	{
		if (datas->b.head->nb < datas->b.last->nb)
			ft_rrr(datas);
		else
			ft_rra(datas, 1);
		datas->move_count++;
	}
	ft_pa(datas);
	while (datas->b.head != NULL && datas->b.head->nb > datas->median && datas->b.head->nb > datas->a.head->nb && datas->b.head->nb < datas->a.last->nb)
		ft_pa(datas);
	// printf ("mc = %d\n", datas->move_count);
	while (datas->move_count > 0)
	{
		ft_ra(datas, 1);
		datas->move_count--;
	}
	ft_ra(datas, 1);
}

void sort_stack(t_datas *datas)
{
	// printf("\n\n\n\n\n");
	best_move(datas);
	while (datas->b.head != NULL) // tant que stack b pas vide, on trie
	{
		// printstack(datas);
		// head b
		if (datas->b.head->nb < datas->median)
		{
			inferior_to_median(datas);
		}
		else
		{
			superior_to_median(datas);
		}
		datas->move_count = 0;
		// last b
	}
}

/*
	Push all nb in the stack b except min max and median
*/
void sort_bigger_stack(t_datas *datas)
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
}

/* Obtain tab of the sorted arguments */
int sorted_tab(t_datas *datas)
{
	int i;
	int sorted;
	long long int swp;

	i = 1;
	sorted = 0;
	while (i < datas->nb_elem)
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
