/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/05/22 04:35:48 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Push all int in the tab in a
Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end  */
void	init_a(t_datas *datas)
{
	int i;

	i = datas->nb_elem - 1;
	if (!append(&datas->a.head, &datas->a.last, datas->tab[i]))
		error_case(datas, 4);
	while (i > 0)
	{
		i--;
		if (!push(&datas->a.head, datas->tab[i]))
			error_case(datas, 4);
	}
	datas->a.size = datas->nb_elem;
}

void	manage_args(int argc, char **argv, t_datas *datas)
{
	datas->argc = argc;
	datas->argv = argv;
	datas->move_count = 0;
	if (argc == 2)
		case_arg_str(datas);
	else
		case_arg_list(datas);
	check_duplicates(datas);
	check_not_integer(datas);
}

void	push_swap(t_datas *datas)
{
    //printf("nb arg = %d\n", datas->nb_elem);
    sorted_tab(datas);
	if (datas->nb_elem == 2 && !check_sort(datas->a))
		ft_sa(datas, 1);
    else if (datas->nb_elem == 3)
        sort_three(datas);
    else if (datas->nb_elem == 5 && !check_sort(datas->a))
        sort_five(datas);
    else if (!check_sort(datas->a))
		radix_sort(datas);
    //sort_bigger_stack(datas);
}

int	main(int argc, char **argv)
{
	t_datas datas;

	ft_memset(&datas, 0, sizeof(t_datas));
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (!argv[1])
		error_case(&datas, 3);
	manage_args(argc, argv, &datas);
	init_a(&datas);
	//printstack(&datas);
	push_swap(&datas);
	//printstack(&datas);
	clear_list(&datas.a);
	clear_list(&datas.b);
	free(datas.tab);
	return (0);
}