/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/03/20 15:04:47 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*empty_stack(void)
{
	return (NULL);
}

void	init_a(t_stack *a, int *tab_args)
{
	
	
} 

void    push_swap()
{
    //while (!(sorted()))
}

int		manage_args(int argc, char **argv, t_datas *datas)
{
	int i;

	i = 1;
	if (argc == 2) //cas str
	{
		if (check_error(datas)) //check str (full int)
			return (error_case());
		datas->tab = atoi_args(argc, ft_split(argv[1], ' '));
	}
	else //cas ints
	{
		if (check_error(datas)) //check si full int
			return (error_case());
		datas->tab = malloc(sizeof(int) * argc - 1);
		if (!(datas->tab))
			return (error_case());
		while (i < (argc - 1))
			*(datas->tab)++ = argv[i++];
	}
	init_a(datas->&a, datas->tab);
	free (datas->tab);
	return (1);
}

int main(int argc, char **argv)
{
	t_datas datas;

	if (argc < 2)
		return (error_case());
	if (!manage_args(argc, argv, &datas))
		return (0);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	push_swap(&datas);
	//free
	// ft_lstclear(a);
	// ft_lstclear(b);
	return (0);
}
