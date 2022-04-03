/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:36:47 by user42            #+#    #+#             */
/*   Updated: 2022/04/03 23:40:02 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_elem(char **nbs)
{
	int i;

	i = 0;
	while (nbs[i])
		i++;
	//printf ("nb elem = %d\n", i);
	return (i);
}


/*
** Returns the int tab corresponding from the sr parameter
*/

long long int	*atoi_args(t_datas *datas, char **nbs)
{
	int i;
	long long int *tab_args;

	i = 0;
	tab_args = malloc(sizeof(long long int) * datas->nb_elem);
	if (!tab_args)
		return (0);
	while(i < datas->nb_elem)
	{
		tab_args[i] = ft_atoll(nbs[i]);
		i++;
	}
	return (tab_args);
}
