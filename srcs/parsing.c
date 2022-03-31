/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:36:47 by user42            #+#    #+#             */
/*   Updated: 2022/03/31 04:07:27 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_elem(char **nbs)
{
	int i;

	i = 0;
	while (nbs[i])
		i++;
	printf ("nb elem = %d\n", i);
	return (i);
}


/*
** Returns the int tab corresponding from the sr parameter
*/

int	*atoi_args(char **nbs)
{
	int i;
	int *tab_args;
	int	nb_elem;

	i = 0;
	nb_elem = count_elem(nbs);
	tab_args = malloc(sizeof(int) * nb_elem);
	if (!tab_args)
		return (0);
	while(i < nb_elem)
	{
		tab_args[i] = ft_atoi(nbs[i]);
		i++;
	}
	return (tab_args);
}

/*
explications de martin

char **args = ft_split(argv[1]);
//proteger le split
int argcount = ft_argcount(args);
int	i = 0;
while (i < argcount)
{
	//on check les erreurs
	if (ft_strcheck_each(args[i], &ft_isdigit) == 0)
		error;
	int negative = 0;
	if (args[i][0] == '-')
		negative = 1;
	else
		negative = 0;
	int value;
	value = ft_atoi(args[i]);
	if (value < 0 && negative == 0)
		overflow;
	if (value > 0 && negative == 1)
		underflow;	
}

char -> [-128, 127];00
char c = 127;
c++;

int i = 2147483647 + 1
i = -2147483648;
*/