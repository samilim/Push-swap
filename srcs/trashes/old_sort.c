/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:59:13 by salimon           #+#    #+#             */
/*   Updated: 2022/05/15 19:41:57 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"




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




//OLD
// void rotate_to_index(t_datas *datas, long long int *actual_b)
// {
// 	while (datas->b.head->nb != actual_b[datas->best_move[1]])
// 	{
// 		if (datas->a.head->nb < actual_b[datas->best_move[1]])
// 		{
// 			ft_rr(datas);
// 			datas->move_count++;
// 		}
// 		else
// 			ft_rb(datas, 1);
// 	}
// 	while (datas->b.head->nb > datas->a.head->nb)
// 	{
// 		ft_ra(datas, 1);
// 		datas->move_count++;
// 	}
// 	ft_pa(datas);
// 	while (datas->b.head != NULL && datas->b.head->nb < datas->median && datas->b.head->nb < datas->a.head->nb && datas->b.head->nb > datas->a.last->nb)
// 		ft_pa(datas);
// 	// datas->move_count++;
// 	while (datas->move_count-- > 0)
// 	{
// 		if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
// 		    ft_rrr(datas);
// 		else
// 		ft_rra(datas, 1);
// 	}
// 	datas->move_count = 0;
// }



//OLD
// void reverse_to_index(t_datas *datas, long long int *actual_b)
// {
// 	while (datas->b.head->nb != actual_b[datas->best_move[1]])
// 	{
// 		if (datas->a.head->nb > actual_b[datas->best_move[1]])
// 		{
// 			ft_rrr(datas);
// 			datas->move_count++;
// 		}
// 		else
// 			ft_rrb(datas, 1);
// 	}
// 	while (datas->b.head->nb < datas->a.last->nb)
// 	{
// 		ft_rra(datas, 1);
// 		datas->move_count++;
// 	}
// 	ft_pa(datas);
// 	while (datas->b.head != NULL && datas->b.head->nb > datas->median && datas->b.head->nb > datas->a.head->nb && datas->b.head->nb < datas->a.last->nb)
// 		ft_pa(datas);
// 	// printf ("mc = %d\n", datas->move_count);
// 	while (datas->move_count > 0)
// 	{
// 		ft_ra(datas, 1);
// 		datas->move_count--;
// 	}
// 	ft_ra(datas, 1);
// }

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