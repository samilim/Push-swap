/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:21:59 by user42            #+#    #+#             */
/*   Updated: 2022/05/16 00:15:23 by salimon          ###   ########.fr       */
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

void rotate_to_index(t_datas *datas, long long int *actual_b)
{
	int i;

	i = 0;
	//printf("rotate\n");
	while (datas->b.head->nb != actual_b[datas->best_move[1]])
	{
		if (i != datas->best_move[2])
		{
			i++;
			ft_rr(datas);
			datas->move_count++; //
		}
		else
			ft_rb(datas, 1);
	}
	while (i != datas->best_move[2] /*datas->b.head->nb > datas->a.head->nb*/) //tant que best move n'est pas a sa place
	{
		i++;
		ft_ra(datas, 1);
		datas->move_count++;
	}
	ft_pa(datas);
	while (datas->b.head != NULL && datas->b.head->nb < datas->a.head->nb && datas->b.head->nb > datas->a.last->nb)
		ft_pa(datas);
	// datas->move_count++;
	// while (datas->move_count-- > 0)
	// {
	// 	if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
	// 	    ft_rrr(datas);
	// 	else
	// 	ft_rra(datas, 1);
	// }
	datas->move_count = 0;
}

void reverse_to_index(t_datas *datas, long long int *actual_b)
{
	int i;

	i = datas->a.size - 1;
	//printf("reverse\n");
	while (datas->b.head->nb != actual_b[datas->best_move[1]])
	{
		//printf("boucle\n");
		if (i != datas->best_move[2])
		{
			i--;
			ft_rrr(datas);
			datas->move_count++;
		}
		else
			ft_rrb(datas, 1);
	}
	while (i != datas->best_move[2] /*datas->b.head->nb < datas->a.last->nb*/)
	{
		i--;
		ft_rra(datas, 1);
		datas->move_count++;
	}
	if (datas->b.head->next != NULL)
		ft_rra(datas, 1);
	ft_pa(datas);
	while (datas->b.head != NULL && datas->b.head->nb < datas->a.head->nb && datas->b.head->nb > datas->a.last->nb)
		ft_pa(datas);
	// printf ("mc = %d\n", datas->move_count);
	// while (datas->move_count > 0)
	// {
	// 	ft_ra(datas, 1);
	// 	datas->move_count--;
	// }
	// ft_ra(datas, 1);
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

int		get_index_in_a(t_datas *datas, long long int *actual_a, long long int element)
{
	int i;

	//printf("element = %lld\n", element);
	//if (datas->b.head->next == NULL)
	//i = 0;
	//else
		i = 1;
	if (actual_a[0] > element && actual_a[datas->a.size - 1] < element)
		return (0);
	while (i < datas->a.size && !(element > actual_a[i - 1] && element < actual_a[i]))
	{
		i++;
	}
	//printf("I EGAL %d\n", i);
	return (i);
}

//lit premiere moitie de b
void	head_count(t_datas *datas, long long int *actual_a, long long int *actual_b)
{
	int j;
	int p_bonus;
	int count;
	int rb;
	int index_in_a;

	rb = 0;
	j = 0; //lit dans stack b
	datas->best_move[0] = 1; //count
	while (rb < datas->best_move[0] && (j < datas->b.size / 2 || datas->b.size == 1)) //tant qu'onne surpasse pas la lecture de head
	{
		index_in_a = get_index_in_a(datas, actual_a, actual_b[j]); //obtain index of actual_b[j] in a
		//printf("index of %lld in a is %d\n", actual_b[j], index_in_a);
		//printf("entre\n\n");
		count = 1; //push
		p_bonus = j + 1;
		if (index_in_a < datas->a.size / 2)
		{
			count += index_in_a + rb; //+rb ?
			while (p_bonus < datas->b.size && actual_b[p_bonus] < actual_b[p_bonus - 1] && actual_b[p_bonus] > actual_a[datas->a.size -1]) //push consecutifs sans rotate
			{
				p_bonus++;
				count--;
			}
			if (rb == 0 || count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
				datas->best_move[2] = index_in_a;
			}
		}
		else
		{
			count += ((datas->a.size) - index_in_a);
			while (p_bonus < datas->b.size && actual_b[p_bonus] < actual_b[p_bonus - 1] && actual_b[p_bonus] > actual_a[datas->a.size -1])
			{
				p_bonus++;
				count--;
			}
			if (rb == 0 || count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
				datas->best_move[2] = index_in_a;
			}
		}
		j++;
		rb++;
	}
}

//lit b a partir de la fin
void	tail_count(t_datas *datas, long long int *actual_a, long long int *actual_b)
{
	int j;
	int p_bonus;
	int count;
	int rrb;
	int index_in_a;

	//printf("tail\n");
	rrb = 1;
	j = datas->b.size - 1;
	while (rrb < datas->best_move[0] && j >= datas->b.size / 2)
	{
		index_in_a = get_index_in_a(datas, actual_a, actual_b[j]);
		//printf("index of %lld in a is %d\n", actual_b[j], index_in_a);
		count = 1; //push
		p_bonus = j + 1;
		if (index_in_a < datas->a.size / 2) //if index dans la pemiere moitie de a
		{
			count += index_in_a + rrb;
			while (p_bonus < datas->b.size && actual_b[p_bonus] < actual_b[p_bonus - 1] && actual_b[p_bonus] > actual_a[datas->a.size -1])
			{
				p_bonus++;
				count--;
			}
			if (count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
				datas->best_move[2] = index_in_a;
			}
		}
		else
		{
			count += ((datas->a.size) - index_in_a);
			while (p_bonus < datas->b.size && actual_b[p_bonus] < actual_b[p_bonus - 1] && actual_b[p_bonus] > actual_a[datas->a.size -1])
			{
				p_bonus++;
				count--;
			}
			if (count < datas->best_move[0])
			{
				datas->best_move[0] = count;
				datas->best_move[1] = j;
				datas->best_move[2] = index_in_a;
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
	head_count(datas, actual_a, actual_b);
	if (datas->best_move[0] > 1)
		tail_count(datas, actual_a, actual_b);
}

//b 49 48 45 21 19 7 5
//a 50 1 2 20 33 47

// 4 5 6 7 8 1 2 3
void	rearrange_a(t_datas *datas, long long int *actual_a)
{
	int i;

	i = 0;
	while (actual_a[i] != datas->min)
		i++;
	if (i < datas->a.size / 2)
	{
		while (datas->a.head->nb != datas->min)
			ft_ra(datas, 1);
	}
	else
	{
		while (datas->a.head->nb != datas->min)
			ft_rra(datas, 1);
	}
}

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
		printstack(datas);

		get_best_move(datas, actual_a, actual_b); //actualise best_move variable to know wich element of b I should push in a
		
		//printf ("best : %lld (index b : %d), (index a : %d)\n", actual_b[datas->best_move[1]], datas->best_move[1], datas->best_move[2]);
		//printf("size a : %d\n", datas->a.size);
		//printf("size b : %d\n", datas->b.size);
		
		if (actual_b[datas->best_move[2]] < (datas->a.size / 2)) //si best move dans premier partie de a, rotate
			rotate_to_index(datas, actual_b);
		else
			reverse_to_index(datas, actual_b);
		//rearrange();
		free (actual_a);
		free (actual_b);
	}
	actual_a = stack_to_tab(datas->a, datas->a.size);
	rearrange_a(datas, actual_a);
	free (actual_a);
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
