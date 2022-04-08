/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 20:01:48 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
make && valgrind --leak-check=full --track-origins=yes ./push_swap "5 2 6 9 +66661"
*/

#include "../includes/push_swap.h"

void	*empty_stack(void)
{
	return (NULL);
}

int push(struct s_elem** head_ref, long long int new_data)
{
    /* 1. allocate node */
    struct s_elem* new_node;
    new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return (4);
 
    /* 2. put in the data  */
    new_node->nb = new_data;
 
    /* 3. Make next of new node as head and previous as NULL
     */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
	return (0);
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
int append(t_datas *datas, struct s_elem** head_ref, long long int new_data)
{
    /* 1. allocate node */
    struct s_elem* new_node;
    new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return (4);
    datas->a.last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->nb = new_data;
 
    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return (0);
    }
 
    /* 5. Else traverse till the last node */
    while (datas->a.last->next != NULL)
        datas->a.last = datas->a.last->next;
 
    /* 6. Change the next of last node */
    datas->a.last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = datas->a.last;
    return (0);
}

/* 
	Push all int in the tab in a
	Given a reference (pointer to pointer) to the head
	of a DLL and an int, appends a new node at the end  */
int	init_a(t_datas *datas)
{
	int i;

	i = datas->nb_elem - 1;
	append(datas, &datas->a.head, datas->tab[i]);
	while (i > 0)
	{
		i--;
		push(&datas->a.head, datas->tab[i]);
	}
	return (0);
}

int	manage_args(int argc, char **argv, t_datas *datas)
{
	int error;
	//struct t_elem* head = NULL;

	datas->argc = argc;
	datas->argv = argv;
	error = 0;
	if (argc == 2) //cas str
	{
		error = case_arg_str(datas);
		if (error)
			return (error);
	}
	else //cas ints ; place tous les arguments dans un tableau d'int
	{
		error = case_arg_list(datas);
		if (error)
			return (error);
	}
	//printf("last check error\n");
	error = check_error(datas);
	if (error) //check si full int et doublons
		return (error);
	printf("NO ERROR\n");
	return (0);
}

void printstack(t_datas	*datas)
{
    printf("\nTraversal in forward direction (top to bottom of the list)\n");
    while (datas->a.head != NULL) {
        printf("%lld ", datas->a.head->nb);
        datas->a.last = datas->a.head;
        datas->a.head = datas->a.head->next;
    }
	printf("\nTraversal in reverse direction \n");
    while (datas->a.last != NULL) {
        printf("%lld ", datas->a.last->nb);
        datas->a.last = datas->a.last->prev;
	}
}

int	main(int argc, char **argv)
{
	t_datas datas;
	int error;

	//printf("argc = %d\n", argc);
	datas.a.head = NULL;
	datas.b.head = NULL;
	ft_memset(&datas, 0, sizeof(t_datas));
	if (argc < 2)
		return (error_case(&datas, 1));
	error = manage_args(argc, argv, &datas);
	if (error > 0 && error != 7)
		return (error_case(&datas, error));
	init_a(&datas);
	printstack(&datas);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	//push_swap(&datas);
	//free
	free(datas.tab);
	return (0);
}
