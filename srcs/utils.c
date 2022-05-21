/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 05:33:06 by salimon           #+#    #+#             */
/*   Updated: 2022/05/21 05:35:23 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void printstack(t_datas	*datas)
{
	t_elem *tmp;

	tmp = datas->a.head;
    printf("\na :\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        tmp = tmp->next;
    }
	// printf("\na in reverse direction \n");
	// while (datas->a.last != NULL) {
    //     printf("%lld ", datas->a.last->nb);
    //     datas->a.last = datas->a.last->prev;
	// }
	tmp = datas->b.head;
	printf("\nb :\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        //datas->b.last = tmp;
        tmp = tmp->next;
    }
	printf("\n\n\n");
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