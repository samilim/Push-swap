/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:36:47 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 00:59:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int	*atoi_args(int argc, char **argv)
{
	int i;
	int j;
	int *tab_args;

	i = 0;
	j = 0;
	tab_args = malloc(sizeof(int) * (argc -1));
	if (!tab_args)
		return (0); //???
	while(argc > 0)
	{
		tab_args[j] = ft_atoi(argv[i]);
		i++;
		j++;
		argc--;
	}
	return (tab_args);
}