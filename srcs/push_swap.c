/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 17:27:14 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*empty_stack(void)
{
	return (NULL);
}

/* 
	Push all int in the tab in a
	Given a reference (pointer to pointer) to the head
	of a DLL and an int, appends a new node at the end  */
void	init_a(t_datas *datas)
{
	datas->a.head = NULL;
	/* 1. allocate node */
	struct s_elem*	new_node;
	new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return/**/;

	datas->a.last = datas->a.head; /* used in step 5*/

	/* 2. put in the data  */
	new_node->nb = datas->tab[0];

	/* 3. This new node is going to be the last node, so make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (datas->a.head == NULL)
	{
		new_node->prev = NULL;
		datas->a.head = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (datas->a.last->next != NULL)
		datas->a.last = datas->a.last->next;

	/* 6. Change the next of last node */
	datas->a.last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = datas->a.last;
	return;
}

void	push_swap()
{

}

int	case_arg_str(t_datas *datas)
{
	int error;
	char **split_str;

	//split_str = NULL;
	split_str = ft_split(datas->argv[1], ' ');
	if (!split_str)
		return (4);
	datas->nb_elem = count_elem(split_str);
	//printf("\ncas str\n");
	error = check_str(datas, split_str);
	if (error > 0) //check si str full chiffres et pas d'espaces en trop (ou gerer les espaces dams count elem)
	{
		free_matrice(split_str);
		return (error);
	}
	//printf("pas d'erreur\n");
	datas->tab = atoi_args(datas, split_str); // fragmente la str et place les int dans un tab d'int
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
	int i ;
	int j;

	datas->nb_elem = datas->argc - 1;
	j = 0;
	i = 1;
	//printf("\ncas ints\n");
	//check fll int avant tab
	while (i < (datas->argc))
	{
		j = 0;
		if ((datas->argv[i][j] == '-' || datas->argv[i][j] == '+') && (datas->argv[i][j + 1] >= '1' && datas->argv[i][j + 1] <= '9')) //gerer +?
			j++;
		while (datas->argv[i][j])
		{
			//printf("digit ? %s\n", &datas->argv[i][j]);
			//printf("(check if digit) current str[] = '%c'\n", datas->argv[1][i]);
			if (!ft_isdigit(datas->argv[i][j]))
				return (3);
			j++;
		}
		i++;
	}
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

int	manage_args(int argc, char **argv, t_datas *datas)
{
	int error;
	//struct t_elem* head = NULL;

	datas->argc = argc;
	datas->argv = argv;
	if (argc == 2) //cas str
	{
		error = case_arg_str(datas);
		if (error > 0)
		{
			//free_matrice(tab);
			return (error);
		}
	}
	else //cas ints ; place tous les arguments dans un tableau d'int
	{
		error = case_arg_list(datas);
		if (error > 0)
		{
			//free_matrice(tab);
			return (error);
		}
		
	}
	//printf("last check error\n");
	error = check_error(datas);
	if (error > 0) //check si full int et doublons
	{
		printf("HELLO\n");
		return (error);
	}
	free(datas->tab);
	printf("NO ERROR\n");
	return (0);
}

void printstack(t_datas	*datas)
{
    printf("\nTraversal in forward direction \n");
    while (datas->a.head != NULL) {
        printf(" %d ", datas->a.head->nb);
        datas->a.last = datas->a.head;
        datas->a.head = datas->a.head->next;
    }
}

int	main(int argc, char **argv)
{
	t_datas datas;
	int error;

	//printf("argc = %d\n", argc);

	ft_memset(&datas, 0, sizeof(t_datas));
	if (argc < 2)
		return (error_case(&datas, 1));
	error = manage_args(argc, argv, &datas);
	if (error > 0 && error != 7)
		return (error_case(&datas, error));
	//datas.b.head = NULL;
	//init_a(&datas);
	//printstack(&datas);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	//free
	return (0);
}
