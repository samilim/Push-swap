/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:12:28 by user42            #+#    #+#             */
/*   Updated: 2022/04/10 23:02:36 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Print an error message corresonding to the code error
*/
int	error_case(t_datas *datas, unsigned int error_code)
{
	if (error_code == 1)
		write (STDERR_FILENO, "Not enough arguments\n", 22);
	if (error_code == 2)
		write (STDERR_FILENO, "Overflow / Underflow\n", 22);
	if (error_code == 3)
		write (STDERR_FILENO, "Invalid parameter(s)\n", 22);
	if (error_code == 4)
		write (STDERR_FILENO, "Allocation error\n", 18);
	if (error_code == 5)
		write (STDERR_FILENO, "Found a duplicate\n", 19);
	if (error_code == 6)
		write (STDERR_FILENO, "Invalid operation ; empty stack\n", 33);
	if (datas->tab)
		free(datas->tab);
	clear_list(&datas->a);
	clear_list(&datas->b);
	return (error_code);
}

int	found_dup(t_datas *datas, long long int *save, int nb, int i)
{
	int	j;

	j = 0;
	while (j < datas->nb_elem)
	{
		if (save[j] == nb && (j != i))
			return (1);
		j++;
	}
	return (0);
}

int	check_duplicates(t_datas *datas)
{
	long long int		*save;
	int					i;

	i = 0;
	save = ft_llintabdup(datas->tab, datas->nb_elem);
	if (!save)
		return (4);
	while (i < datas->nb_elem)
	{
		if (found_dup(datas, save, datas->tab[i], i) == 1)
		{
			free (save);
			return (5);
		}
		i++;
	}
	free (save);
	return (0);
}

int	check_not_integer(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->nb_elem)
	{
		if (datas->tab[i] >= -2147483648 && datas->tab[i] <= 2147483647)
			i++;
		else
			return (2);
	}
	return (0);
}

/*
** Check if 
** the int tab created from the arguments 
** contain duplicates or over/underflows.
*/

int	check_error(t_datas *datas)
{
	if (check_duplicates(datas) > 0)
		return (5);
	if (check_not_integer(datas) > 0)
		return (2);
	return (0);
}
