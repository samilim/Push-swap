/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:12:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/20 14:18:57 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_duplicates(int *tab_nb)
{
	int *save;
	int 	i;

	save = ft_strdup(tab_nb); //DUP INT
	while (tab_nb[i])
	{
		if (found_dup(save, tab_nb[i]))
		{
			write (1, "Found a duplicate\n", 19);
			return (1);
		}
		i++;
	}
	free (save);
	return (0);
}

int		check_not_integer(int argc, char **argv)
{
	

}

int		check_error(int argc, char **argv)
{
	if (check_duplicates(argv, argc) || check_not_integer(argv, argc))
	{
		return (1);
	return (0);
//error : param non int ou doublon et si instructions n'existent pas pour bonus
}