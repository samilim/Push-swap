/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:36:47 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 16:25:57 by salimon          ###   ########.fr       */
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

// int	manage_args(int argc, char **argv, t_datas *datas)
// {
// 	int i;
// 	int j;
// 	int error;
// 	char **tab;
// 	//struct t_elem* head = NULL;

// 	j = 0;
// 	i = 0;
// 	datas->argc = argc;
// 	datas->argv = argv;
// 	tab = NULL; //
// 	if (argc == 2) //cas str
// 	{
// 		tab = ft_split(datas->argv[1], ' ');
// 		if (!tab)
// 			return (4);
// 		datas->nb_elem = count_elem(tab);
// 		//printf("\ncas str\n");
// 		error = check_error(datas, tab, 1);
// 		if (error > 0) //check si str full chiffres et pas d'espaces en trop (ou gerer les espaces dams count elem)
// 		{
// 			free_matrice(tab);
// 			return (error);
// 		}
// 		//printf("pas d'erreur\n");
// 		datas->tab = atoi_args(datas, tab); // fragmente la str et place les int dans un tab d'int
// 		if (!datas->tab)
// 		{
// 			free_matrice(tab);
// 			return (4);
// 		}
// 	}
// 	else //cas ints ; place tous les arguments dans un tableau d'int
// 	{
// 		datas->nb_elem = argc - 1;
// 		j = 0;
// 		i = 1;
// 		//printf("\ncas ints\n");
// 		//check fll int avant tab
// 		while (i < (datas->argc))
// 		{
// 			j = 0;
// 			if (datas->argv[i][j] == '-' || datas->argv[i][j] == '+') //gerer +?
// 				j++;
// 			while (datas->argv[i][j])
// 			{
// 				//printf("digit ? %s\n", &datas->argv[i][j]);
// 				//printf("(check if digit) current str[] = '%c'\n", datas->argv[1][i]);
// 				if (!ft_isdigit(datas->argv[i][j]))
// 					return (3);
// 				j++;
// 			}
// 			i++;
// 		}
// 		j = 0;
// 		datas->tab = malloc(sizeof(long long int) * datas->nb_elem);
// 		if (!(datas->tab))
// 		{
// 			if (tab != NULL)
// 				free_matrice(tab);
// 			return (error_case(datas, 4));
// 		}
// 		while (j < (datas->nb_elem))
// 		{
// 			datas->tab[j] = ft_atoll(datas->argv[j + 1]);
// 			j++;
// 		}
// 	}
// 	//printf("last check error\n");
// 	error = check_error(datas, tab, 2);
// 	if (error > 0) //check si full int et doublons
// 	{
// 		if (tab != NULL)//
// 				free_matrice(tab);//
// 		return (error);
// 	}
// 	if (tab != NULL)
// 				free_matrice(tab);
// 	free(datas->tab);
// 	return (0);
// }