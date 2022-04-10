/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/04/10 22:24:49 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
make && valgrind --leak-check=full --track-origins=yes ./push_swap "5 2 6 9 +66661"
gcc -Wall -Wextra -Werror -g3 -fsanitize=address
*/

#include "../includes/push_swap.h"

void	*empty_stack(void)
{
	return (NULL);
}


void	delete_node(struct s_elem** head_ref)
{
	t_elem *tmp;

	tmp = (*head_ref);
	(*head_ref) = (*head_ref)->next;
    free(tmp);
	//(*head_ref)->prev = NULL;
}

/* push en haut de la stack */
int push(struct s_elem** head_ref, long long int new_data)
{
    struct s_elem* new_node;

    new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return (0);
    new_node->nb = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
	return (1);
}

/* appends a new node at the end  */
int append(t_datas *datas, struct s_elem** head_ref, struct s_elem** last_ref, long long int new_data)
{
    struct s_elem* new_node;

    new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return (0);
    *last_ref = *head_ref;
    new_node->nb = new_data;
 
    /* This new node is going to be the last node, so
          make next of it as NULL*/
	new_node->next = NULL;
 
    /* If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return (1);
    }

    /* Else traverse till the last node */
    while ((*last_ref)->next != NULL)
        datas->a.last = datas->a.last->next;
 
    /* Change the next of last node */
    (*last_ref)->next = new_node;
 
    /* Make last node as previous of new node */
    new_node->prev = *last_ref;
    return (1);
}

/* 
	Push all int in the tab in a
	Given a reference (pointer to pointer) to the head
	of a DLL and an int, appends a new node at the end  */
int	init_a(t_datas *datas)
{
	int i;

	i = datas->nb_elem - 1;
	append(datas, &datas->a.head, &datas->a.last, datas->tab[i]);
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
	error = check_error(datas);
	if (error)
		return (error);
	printf("NO ERROR\n");
	return (0);
}

void	clear_list(t_stack *stack)
{
	t_elem *tmp;
	while (stack->head != NULL) {
		tmp = stack->head->next;
        free(stack->head);
		//printf("\nfreenode\n");
        stack->head = tmp;
    }
	if (stack->head != NULL)
		free(stack->head);
	stack->head = NULL;
	//stack->last = NULL;
	//printf("FREE STACK\n");
}

void printstack(t_datas	*datas)
{
	t_elem *tmp;

	tmp = datas->a.head;
    printf("\na in forward direction (top to bottom of the list)\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        datas->a.last = tmp;
        tmp = tmp->next;
    }
	// printf("\na in reverse direction \n");
	// while (datas->a.last != NULL) {
    //     printf("%lld ", datas->a.last->nb);
    //     datas->a.last = datas->a.last->prev;
	// }
	tmp = datas->b.head;
	printf("\nb in forward direction (top to bottom of the list)\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        datas->b.last = tmp;
        tmp = tmp->next;
    }
	printf("\n\n\n");
}

int	main(int argc, char **argv)
{
	t_datas datas;
	int error;

	datas.a.head = NULL;
	datas.b.head = NULL;
	ft_memset(&datas, 0, sizeof(t_datas));
	if (argc < 2)
		return (error_case(&datas, 1));
	error = manage_args(argc, argv, &datas);
	if (error > 0 && error != 7)
		return (error_case(&datas, error));
	init_a(&datas);
	//push_swap(&datas);
	printstack(&datas);
	if (ft_pb(&datas))
		return(error_case(&datas, 4));
	ft_pb(&datas);
	ft_pb(&datas);
	ft_pb(&datas);
	ft_pb(&datas);
	printstack(&datas);
	ft_pa(&datas);
	printstack(&datas);
	//ft_sa(&datas);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	clear_list(&datas.a);
	clear_list(&datas.b);
	free(datas.tab);
	return (0);
}
