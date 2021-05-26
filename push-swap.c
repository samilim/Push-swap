/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:55:07 by salimon           #+#    #+#             */
/*   Updated: 2021/05/26 02:43:55 by user42           ###   ########.fr       */
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
    while (!(sorted()))
}

int main(int argc, char **argv)
{
	t_stack_a a;
	t_stack_b b;
	int	*tab_args;
	
    if (check_error(argv, argc))
		return (0);
	tab_args = atoi_args(argc, argv);
	init_a(a, tab_args);
	free(tab_args);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}

//LIRE LES ARGS ET CHECK LES ERREURS
//atoi les args
//PLACER LES ARGUMENTS DANS A
//ANALYSER A
//TRIER
//free