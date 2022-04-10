/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/04/10 23:25:15 by salimon          ###   ########.fr       */
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
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

/*
** Structure de données des stacks
*/

typedef struct s_stack
{
	struct s_elem	*head;
	struct s_elem	*last;
	int				size;
	int				mediane;
}				t_stack;

/*
** Structure des stacks
*/

typedef struct s_datas
{
	t_stack			a;
	t_stack			b;
	long long int	*tab;
	int				argc;
	char			**argv;
	int				nb_elem;
}				t_datas;

int				check_error(t_datas *datas);
int				case_arg_str(t_datas *datas);
int				case_arg_list(t_datas *datas);
int				count_elem(char **nbs);
int				error_case(t_datas *datas, unsigned int error_code);
long long int	*atoi_args(t_datas *datas, char **nbs);
void			push_swap(t_datas *datas);
void			delete_node(struct s_elem **head_re);
void			clear_list(t_stack *stack);
int				ft_pa(t_datas *datas);
int				ft_pb(t_datas *datas);
int				append(t_datas *datas, struct s_elem **head_ref,
					struct s_elem **last_ref, long long int new_data);
int				push(struct s_elem **head_ref, long long int new_data);

#endif