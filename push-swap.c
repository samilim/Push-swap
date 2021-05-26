/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:55:07 by salimon           #+#    #+#             */
/*   Updated: 2021/05/26 06:29:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"


t_stack_a	*empty_stack(void)
{
	return (NULL);
}

void	init_a(t_stack_a **a, int *tab_args)
{
	t_stack_a *link;
	
	link = malloc(sizeof(int));
	while (*tab_args++)
	{
		link->elem = *tab_args;
		link->next = a;
		
		//link = link->next;
	}
} 

void    push_swap()
{
    //while (!(sorted()))
}

int main(int argc, char **argv)
{
	t_stack_a **a;
	t_stack_b **b;
	int	*tab_args;

	//LIRE LES ARGS ET CHECK LES ERREURS
	if (check_not_integer(argc, argv))
	{

	}
	//atoi les args
	tab_args = atoi_args(argc, argv);
    if (check_duplicate(tab_args))
	{
		write (1, "Error\n", 6);
		return (0);
	}

	//PLACER LES ARGUMENTS DANS A
	init_a(a, tab_args);


	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	push_swap(a, b);
	
	//free
	ft_free_tab(tab_args);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}



