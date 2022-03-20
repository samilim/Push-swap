/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:12:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/20 13:48:03 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		error_case()
{
	write (2, "Error\n", 6);
	return (1);
}

int		check_duplicates(int *tab_args)
{
	int *save;
	int 	i;

	save = ft_strdup(tab_args); //DUP INT
	while (tab_args[i])
	{
		if (found_dup(save, tab_args[i]))
		{
			write ()
			return (1);
		i++;
	}
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