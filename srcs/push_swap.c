/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/04/24 06:04:02 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
make && valgrind --leak-check=full --track-origins=yes ./push_swap "5 2 6 9 +66661"
gcc -Wall -Wextra -Werror -g3 -fsanitize=address
make && valgrind --leak-check=full --track-origins=yes ./push_swap 5 2 6 +94564 55 -9 -3 12 -2 0
make && valgrind --leak-check=full --track-origins=yes ./push_swap 5 2 6 +94564 55 -9 -3 12 -2 13 16 59 75 96 100 41 36 22 11 66 -78
*/

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
	if (argc == 2) //cas str 
		case_arg_str(datas);
	else //cas ints ; place tous les arguments dans un tableau d'int
		case_arg_list(datas);
	/*
	** Check if 
	** the int tab created from the arguments 
	** contain duplicates or over/underflows.
	*/
	check_duplicates(datas);
	check_not_integer(datas);
	printf("NO ERROR\n");
}

void printstack(t_datas	*datas)
{
	t_elem *tmp;

	tmp = datas->a.head;
    printf("\na actually :\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        tmp = tmp->next;
    }
	// printf("\na in reverse direction \n");
	// while (datas->a.last != NULL) {
    //     printf("%lld ", datas->a.last->nb);
    //     datas->a.last = datas->a.last->prev;
	// }
	// tmp = datas->b.head;
	// printf("\nb in forward direction (top to bottom of the list)\n");
    // while (tmp != NULL) {
    //     printf("%lld ", tmp->nb);
    //     //datas->b.last = tmp;
    //     tmp = tmp->next;
    // }
	printf("\n\n\n");
}

int	test_operations(t_datas *datas)
{
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	printstack(datas);
	ft_pa(datas);
	printstack(datas);
	ft_sa(datas, 0);
	printstack(datas);
	ft_sa(datas, 0);
	printstack(datas);
	ft_sb(datas, 0);
	printstack(datas);
	ft_ss(datas);
	printstack(datas);
	ft_ra(datas, 0);
	printstack(datas);
	ft_ra(datas, 0);
	printstack(datas);
	ft_rb(datas, 0);
	printstack(datas);
	ft_rr(datas);
	printstack(datas);
	ft_rra(datas, 0);
	printstack(datas);
	ft_rra(datas, 0);
	printstack(datas);
	ft_rrb(datas, 0);
	printstack(datas);
	ft_rrr(datas);
	printstack(datas);
	return (0);
}

int	main(int argc, char **argv)
{
	t_datas datas;

	datas.a.head = NULL;
	datas.b.head = NULL;
	datas.b.size = 0;
	ft_memset(&datas, 0, sizeof(t_datas));
	if (argc < 2)
		error_case(&datas, 1);
	manage_args(argc, argv, &datas);
	
	init_a(&datas);
	printstack(&datas);

	push_swap(&datas);
	//if (error > 0)
	//	return (error_case(&datas, error));
	printstack(&datas);
	
	//test_operations(&datas);
	//printstack(&datas);
	
	clear_list(&datas.a);
	clear_list(&datas.b);
	free(datas.tab);
	return (0);
}
