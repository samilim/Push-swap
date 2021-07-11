/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 01:13:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		manage_args(int argc, char **argv, t_stack_a a)
{
	int	*tab_int;
	int i;

	i = 1;
	if (argc == 2 && argv[1][0] == '"' && argv[1][ft_strlen(argv[1]) - 1] == '"')
	{
		if (check_error(argc, argv)) //check str (full int)
			return (error_case());
		tab_int = atoi_args(argc, argv);
	}
	else
	{
		if (check_error(argc, argv)) //check si full int
			return (error_case());
		tab_int = malloc(sizeof(int) * argc - 1); //mettre un \0 ou pas?
		if (!tab_int)
			return (error_case());
		while (i < (argc - 1))
			*tab_int++ = argv[i++];
	}
	init_a(a, tab_int);
	free (tab_int);
	return (1);
}

int main(int argc, char **argv)
{
	t_stack_a **a;
	t_stack_b **b;
	
	if (argc < 2)
		return (error_case());
	if (!manage_args(argc, argv, **a))
		return (0);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	push_swap(a, b);
	//free
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}



