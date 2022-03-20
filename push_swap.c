/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/03/20 13:46:35 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*empty_stack(void)
{
	return (NULL);
}

void	init_a(int argc, t_stacks stacks, int *tab_args)
{

	while ()
	
} 

void    push_swap()
{
    //while (!(sorted()))
}

int		manage_args(int argc, char **argv, t_datas *datas)
{
	int	*tab_int;
	int i;

	i = 1;
	if (argc == 2)
	{
		if (check_error(argc, argv)) //check str (full int)
			return (error_case());
		tab_int = atoi_args(argc, ft_split(argv[1], ' '));
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
	t_datas datas;

	if (argc < 2)
		return (error_case());
	if (!manage_args(argc, argv, &datas))
		return (0);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	push_swap(&datas);
	//free
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}



