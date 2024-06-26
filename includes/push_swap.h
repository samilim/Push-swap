/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/05/22 03:26:52 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

/* 
** Structure de données des éléments
*/

typedef struct s_elem
{
	long long int	nb;
	int				index;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

/*
** Structure de navigation des stacks
*/

typedef struct s_stack
{
	struct s_elem	*head;
	struct s_elem	*last;
	int				size;
}				t_stack;

/*
** Struture des stacks
** tab contains the sorted version of the stacks a
** tabix is a non sorted version of tab that I use in my radix sort algo
** best_move[0] = count, [1] = index in b, [2] = index in a
*/

typedef struct s_datas
{
	t_stack			a;
	t_stack			b;
	long long int	*tab;
	//long long int	(*tabix)[2];
	int				argc;
	char			**argv;
	int				nb_elem;
	long long int	min;
	long long int	max;
	long long int	median;
	int				move_count;
	int				best_move[3];
}				t_datas;

/* parsing */
void				check_error(t_datas *datas);
void				check_not_integer(t_datas *datas);
void				check_duplicates(t_datas *datas);
void				case_arg_str(t_datas *datas);
void				case_arg_list(t_datas *datas);
int					count_elem(char **nbs);
int					error_case(t_datas *datas, unsigned int error_code);
long long int		*atoi_args(t_datas *datas, char **nbs);
/* sorting */
void				push_swap(t_datas *datas);
void				sort_three(t_datas *datas);
void				sort_five(t_datas *datas);
void				sort_bigger_stack(t_datas *datas);
void				radix_sort(t_datas *datas);
/* utils */
void				delete_node(struct s_elem **head_re);
void				clear_list(t_stack *stack);
int					check_sort(t_stack stack);
int					sorted_tab(t_datas *datas);
long long int		*stack_to_tab(t_stack a, int size);
/* operations */
void				ft_pa(t_datas *datas);
void				ft_pb(t_datas *datas);
void				ft_sa(t_datas *datas, int print);
void				ft_sb(t_datas *datas, int print);
void				ft_ss(t_datas *datas);
void				ft_ra(t_datas *datas, int print);
void				ft_rb(t_datas *datas, int print);
void				ft_rr(t_datas *datas);
void				ft_rra(t_datas *datas, int print);
void				ft_rrb(t_datas *datas, int print);
void				ft_rrr(t_datas *datas);
int					append(struct s_elem **head_ref,
						struct s_elem **last_ref, long long int new_data);
int					push(struct s_elem **head_ref, long long int new_data);
/* others */
int					sorted_tab(t_datas *datas);
void				printstack(t_datas	*datas);

#endif