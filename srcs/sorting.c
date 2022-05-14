/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/05/14 03:34:04 by salimon          ###   ########.fr       */
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

//OLD
// void inferior_to_median(t_datas *datas)
// {
// 	if (datas->b.head->nb < datas->median)
// 	{
// 		while (datas->b.head->nb > datas->a.head->nb)
// 		{
// 			if (datas->b.head->nb < datas->b.last->nb)
// 				ft_rr(datas);
// 			else
// 				ft_ra(datas, 1);
// 			datas->move_count++;
// 		}
// 		ft_pa(datas);
// 		while (datas->b.head != NULL && datas->b.head->nb < datas->median && datas->b.head->nb < datas->a.head->nb && datas->b.head->nb > datas->a.last->nb)
// 			ft_pa(datas);
// 		// atas->move_count++;
// 	}
// 	while (datas->move_count-- > 0)
// 	{
// 		// if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
// 		//     ft_rrr(datas);
// 		// else
// 		ft_rra(datas, 1);
// 	}
// 	datas->move_count = 0;
// }

void inferior_to_median(t_datas *datas, long long int *actual_b)
{
	while (datas->b.head->nb != actual_b[datas->best_move[1]])
	{
		if (datas->a.head->nb < actual_b[datas->best_move[1]])
		{
			ft_rr(datas);
			datas->move_count++;
		}
		else
			ft_rb(datas, 1);
	}
	while (datas->b.head->nb > datas->a.head->nb)
	{
		ft_ra(datas, 1);
		datas->move_count++;
	}
	ft_pa(datas);
	while (datas->b.head != NULL && datas->b.head->nb < datas->median && datas->b.head->nb < datas->a.head->nb && datas->b.head->nb > datas->a.last->nb)
		ft_pa(datas);
	// datas->move_count++;
	while (datas->move_count-- > 0)
	{
		if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
		    ft_rrr(datas);
		else
		ft_rra(datas, 1);
	}
	datas->move_count = 0;
}

void superior_to_median(t_datas *datas, long long int *actual_b)
{
	while (datas->b.head->nb != actual_b[datas->best_move[1]])
	{
		if (datas->a.head->nb > actual_b[datas->best_move[1]])
		{
			ft_rrr(datas);
			datas->move_count++;
		}
		else
			ft_rrb(datas, 1);
	}
	while (datas->b.head->nb < datas->a.last->nb)
	{
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
	// i =0;
	// while (i < size)
	// {
	// 	printf("%lld ", tab[i]);
	// 	i++;
	// }
	// printf("\n");
	return (tab);
}


void	head_count(t_datas *datas, long long int *actual_a, long long int *actual_b)
{
	int i;
	int j;
	int count;
	int rb;

	rb = 0;
	j = 0; //lit dans stack b
	datas->best_move[0] = 1; //count
	while (rb < datas->best_move[0] && j < datas->b.size / 2) //tant qu'onne surpasse pas la lecture de head
	{
		//printf("entre\n\n");
		count = 1; //push
		if (actual_b[j] < datas->median)
		{
			i = 0;
			while (i < datas->a.size && actual_b[j] > actual_a[i])
			{
				i++;
				count++;
			}
			if (rb == 0 || count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
			}
		}
		else
		{
			i = datas->a.size - 1;
			while (i >= 0 && actual_b[j] < actual_a[i])
			{
				i--;
				count++;
			}
			if (rb == 0 || count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
			}
		}
		j++;
		rb++;
	}
}

void	tail_count(t_datas *datas, long long int *actual_a, long long int *actual_b)
{
	int i;
	int j;
	int count;
	int rrb;

	rrb = 1;
	j = datas->b.size - 1;
	while (rrb < datas->best_move[0] && j >= datas->b.size / 2)
	{
		count = 1; //push
		if (actual_b[j] < datas->median)
		{
			i = 0;
			while (i < datas->a.size && actual_b[j] > actual_a[i])
			{
				i++;
				count++;
			}
			if (count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
			}
		}
		else
		{
			i = datas->a.size - 1;
			while (i >= 0 && actual_b[j] < actual_a[i])
			{
				i--;
				count++;
			}
			if (count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
			}
		}
		j--;
		rrb++;
	}
}

/*
** Obtain the index of the obtimal nb to push in a. recuperer tab de b et si i < moitie lire parle haut, sinon lire par le bas
*/
void get_best_move(t_datas *datas, long long int *actual_a, long long int *actual_b)
{
	//long long int *actual_a;
	//long long int *actual_b;

	//actual_a = stack_to_tab(datas->a, datas->a.size);
	//actual_b = stack_to_tab(datas->b, datas->b.size);
	head_count(datas, actual_a, actual_b);
	tail_count(datas, actual_a, actual_b);
	//free (actual_a);
	//free (actual_b);
}


//OLD
// void sort_stack(t_datas *datas)
// {
// 	// printf("\n\n\n\n\n");
// 	while (datas->b.head != NULL) // tant que stack b pas vide, on trie
// 	{
// 		printstack(datas);
// 		// head b
// 		if (datas->b.head->nb < datas->median)
// 		{
// 			inferior_to_median(datas);
// 		}
// 		else
// 		{
// 			superior_to_median(datas);
// 		}
// 		datas->move_count = 0;
// 		// last b
// 	}
// }

void sort_stack(t_datas *datas)
{
	// printf("\n\n\n\n\n");
	long long int *actual_a;
	long long int *actual_b;

	while (datas->b.head != NULL) // tant que stack b pas vide, trie
	{
		datas->best_move[0] = 1;
		//printf("tab a: ");
		actual_a = stack_to_tab(datas->a, datas->a.size);
		//printf("tab b: ");
		actual_b = stack_to_tab(datas->b, datas->b.size);
		get_best_move(datas, actual_a, actual_b);
		
		
		printstack(datas);
		printf ("best : %lld (index %d)\n", actual_b[datas->best_move[1]], datas->best_move[1]);
		printf("size a : %d\n", datas->a.size);
		printf("size b : %d\n", datas->b.size);

		
		// if (datas->best_move[1] < datas->b.size/2)
		// {
		// 	while (datas->b.head->nb != actual_b[datas->best_move[1]])
		// 	{
		// 		if (datas->a.head->nb < actual_b[datas->best_move[1]] && actual_b[datas->best_move[1]] < datas->median)
		// 		{
		// 			ft_rr(datas);
		// 			datas->move_count++;
		// 		}
		// 		else
		// 			ft_rb(datas, 1);
		// 	}
		// }
		// else
		// {
		// 	while (datas->b.head->nb != actual_b[datas->best_move[1]])
		// 	{
		// 		if (datas->a.last->nb > actual_b[datas->best_move[1]] && actual_b[datas->best_move[1]] > datas->median)
		// 		{
		// 			ft_rrr(datas);
		// 			datas->move_count++;
		// 		}
		// 		else
		// 			ft_rrb(datas, 1);
		// 	}
		// }
		if (actual_b[datas->best_move[1]] < datas->median)
			inferior_to_median(datas, actual_b);
		else
			superior_to_median(datas, actual_b);
		// last b
		free (actual_a);
		free (actual_b);
	}
}

/*
	Push all nb in the stack b except min max and median
*/
void sort_bigger_stack(t_datas *datas)
{
	//printf("***SORT BIGGER STACK***\n");
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
	//printf("***SORT STACK***\n");
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
