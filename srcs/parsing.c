/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:36:47 by user42            #+#    #+#             */
/*   Updated: 2022/04/10 12:57:51 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_elem(char **nbs)
{
	int	i;

	i = 0;
	while (nbs[i])
		i++;
	return (i);
}

/*
** Returns the int tab corresponding from the str parameter
*/

long long int	*atoi_args(t_datas *datas, char **nbs)
{
	int				i;
	long long int	*tab_args;

	i = 0;
	tab_args = malloc(sizeof(long long int) * datas->nb_elem);
	if (!tab_args)
		return (0);
	while (i < datas->nb_elem)
	{
		tab_args[i] = ft_atoll(nbs[i]);
		i++;
	}
	return (tab_args);
}

/*
** Check if the arguments contains only digits and sign
*/

int	check_str(char **tab, int i)
{
	int	j;

	while (tab[i])
	{
		j = 0;
		if ((tab[i][j] == '-' || tab[i][j] == '+') &&
			(tab[i][j + 1] >= '1' && tab[i][j + 1] <= '9'))
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}

int	case_arg_str(t_datas *datas)
{
	int		error;
	char	**split_str;

	split_str = ft_split(datas->argv[1], ' ');
	if (!split_str)
		return (4);
	datas->nb_elem = count_elem(split_str);
	error = check_str(split_str, 0);
	if (error > 0)
	{
		free_matrice(split_str);
		return (error);
	}
	datas->tab = atoi_args(datas, split_str);
	if (!datas->tab)
	{
		free_matrice(split_str);
		return (4);
	}
	free_matrice(split_str);
	return (0);
}

int	case_arg_list(t_datas *datas)
{
	int	j;
	int	error;

	datas->nb_elem = datas->argc - 1;
	error = check_str(datas->argv, 1);
	if (error > 0)
		return (error);
	j = 0;
	datas->tab = malloc(sizeof(long long int) * datas->nb_elem);
	if (!(datas->tab))
		return (4);
	while (j < (datas->nb_elem))
	{
		datas->tab[j] = ft_atoll(datas->argv[j + 1]);
		j++;
	}
	return (0);
}
