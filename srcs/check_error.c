/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:12:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/31 01:49:30 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Print an error message corresonding to the code error
*/
int	error_case(unsigned int error_code)
{
	if (error_code == 1)
		write (STDERR_FILENO, "Not enough arguments\n", 22);
	if (error_code == 3)
		write (STDERR_FILENO, "Non int parameter(s)\n", 22);
	if (error_code == 4)
		write (STDERR_FILENO, "Allocation error\n", 18);
	return (error_code);
}

int	found_dup(int *save, int nb)
{
	while (*save++)
		if (*save == nb)
			return (1);
	return (0);
}

int	*ft_intabdup(int *tab)
{
	int	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (tab[len])
		len++;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (0);
	while (tab[i])
	{
		dest[i] = tab[i];
		i++;
	}
	return (dest);
}

int	check_duplicates(int *tab_nb)
{
	int		*save;
	int		i;

	save = ft_intabdup(tab_nb);
	while (tab_nb[i])
	{
		if (found_dup(save, tab_nb[i]) == 1)
		{
			write (STDERR_FILENO, "Found a duplicate\n", 19);
			return (1);
		}
		i++;
	}
	if (save)
		free (save);
	return (0);
}

int	check_not_integer(int *tab_nb)
{
	while (*tab_nb++)
	{
		if (*tab_nb <= -2147483648 || *tab_nb >= 2147483647)
		{
			write (STDERR_FILENO, "Found a non int argument\n", 26);
			return (1);
		}
	}
	return (0);
}

/*
** First condition is when the arg is a unique str.
** It will check is there are only digit in the string.
** Else it will check if 
** the int tab created from the arguments 
** contain duplicates or over/underflows.
*/
int	check_error(t_datas *datas, unsigned int type_arg)
{
	int	i;

	i = 0;
	if (type_arg == 1)
	{
		while (datas->argv[1][i++])
			if (!ft_isdigit(datas->argv[1][i]))
				return (3);
	}
	else if (check_duplicates(datas->tab) || check_not_integer(datas->tab))
		return (2);
	return (0);
}
