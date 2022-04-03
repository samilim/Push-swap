/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:12:28 by user42            #+#    #+#             */
/*   Updated: 2022/04/03 22:43:45 by salimon          ###   ########.fr       */
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
	if (error_code == 3)
		write (STDERR_FILENO, "Non int parameter(s)\n", 22);
	if (error_code == 4)
		write (STDERR_FILENO, "Allocation error\n", 18);
	if (error_code == 5)
		write (STDERR_FILENO, "Found a duplicate\n", 19);
	free(datas->tab);
	return (error_code);
}

int	found_dup(t_datas *datas, int *save, int nb, int i)
{
	int j;

	j = 0;
	while (j < datas->nb_elem)
	{
		//printf("%d avec nb = %d\n", save[j], nb);
		if (save[j] == nb && (j != i))
			return (1);
		j++;
	}
	return (0);
}

int	*ft_intabdup(t_datas *datas)
{
	int	*dest;
	int		i;

	i = 0;
	//printf("nb_elem = %d\n", datas->nb_elem);
	dest = malloc(sizeof(int) * datas->nb_elem);
	if (!dest)
		return (0);
	while (i < datas->nb_elem)
	{
		dest[i] = datas->tab[i];
		i++;
	}
	return (dest);
}

int	check_duplicates(t_datas *datas)
{
	int		*save;
	int		i;

	i = 0;
	save = ft_intabdup(datas);
	if (!save)
		return (error_case(datas, 4));
	while (i < datas->nb_elem)
	{
		//printf("check dup : %d\n", datas->tab[i]);
		if (found_dup(datas, save, datas->tab[i], i) == 1)
		{
			free (save);
			return (error_case(datas, 5));
		}
		i++;
	}
	free (save);
	return (0);
}

int	check_not_integer(t_datas *datas)
{
	int i;

	i = 0;
	while (i < datas->nb_elem)
	{
		//printf("%d\n", datas->tab[i]);
		if (((long long int)datas->tab[i] <= -2147483648) || ((long long int)datas->tab[i] >= 2147483647))
		{
			//printf("%d\n", datas->tab[i]);
			return (error_case(datas, 3));
		}
		i++;
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
int	check_error(t_datas *datas, char **tab, unsigned int type_arg)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (type_arg == 1)
	{
		//printf("\nargv :\n");
		//printf("%s\n", datas->argv[0]);
		//printf("%s\n\n", datas->argv[1]);
		//printf("check_error : 1\n");
		while (tab[i])
		{
			j = 0;
			if (tab[i][j] == '-' || tab[i][j] == '+') //gerer +?
				j++;
			while (tab[i][j])
			{
				//printf("(check if digit) current str[] = '%c'\n", datas->argv[1][i]);
				if (!ft_isdigit(tab[i][j]))
					return (3);
				j++;
			}
			i++;
		}
		while (datas->argv[1][i])
		{
			//printf("(check if digit) current str[] = '%c'\n", datas->argv[1][i]);
			if (datas->argv[1][i] != ' ' && datas->argv[1][i] != '+' && datas->argv[1][i] != '-' && !ft_isdigit(datas->argv[1][i]))
				return (3);
			i++;
		}
	}
	else if (check_duplicates(datas) > 0 /* || check_not_integer(datas) > 0 */)
		return (2);
	return (0);
}
