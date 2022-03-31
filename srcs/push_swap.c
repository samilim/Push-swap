/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/03/31 07:59:39 by salimon          ###   ########.fr       */
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

int	manage_args(int argc, char **argv, t_datas *datas)
{
	int i;
	int j;
	//char **tab;
	//struct t_elem* head = NULL;

	j = 0;
	i = 0;
	datas->argc = argc;
	datas->argv = argv;
	if (argc == 2) //cas str
	{
		// tab = ft_split(datas->argv[1], ' ');
		// if (!tab)
		// 	return (error_case(4));
		// printf("\ncas str\n");
		// if (check_error(datas, 1) > 0) //check si str full chiffres et pas d'espaces en trop (ou gerer les espaces dams count elem)
		// 	return (error_case(3));
		// printf("pas d'erreur\n");
		// datas->tab = atoi_args(tab); // fragmente la str et place les int dans un tab d'int
		// if (!datas->tab)
		// 	return (error_case(4));
		// while(*tab)
		// 	free(*tab++);
		// if (*tab)
		// 	free (*tab);
	}
	else //cas ints ; place tous les arguments dans un tableau d'int
	{
		j = 0;
		i = 1;
		printf("\ncas ints\n");
		//check fll int avant tab
		while (i < (datas->argc))
		{
			j = 0;
			if (datas->argv[i][j] == '-') //gerer +?
				j++;
			while (datas->argv[i][j])
			{
				printf("digit ? %s\n", &datas->argv[i][j]);
				//printf("(check if digit) current str[] = '%c'\n", datas->argv[1][i]);
				if (!ft_isdigit(datas->argv[i][j]))
					return (error_case(3));
				j++;
			}
			i++;
		}
		j = 0;
		datas->tab = malloc(sizeof(int) * (datas->argc - 1));
		if (!(datas->tab))
			return (error_case(4));
		while (j < (datas->argc - 1))
		{
			datas->tab[j] = ft_atoi(datas->argv[j + 1]);
			j++;
		}
	}
	printf("last check error\n");
	if (check_error(datas, 2) > 0) //check si full int et doublons
		return (error_case(2));
	if (datas->tab)
		free (datas->tab);
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

	printf("argc = %d\n", argc);

	if (argc < 2)
		return (error_case(1));
	if (manage_args(argc, argv, &datas) > 0)
		return (1);
	//datas.b.head = NULL;y
	//init_a(&datas);
	//printstack(&datas);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	//free
	return (0);
}
