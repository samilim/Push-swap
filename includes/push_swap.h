/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/04/16 05:31:53 by salimon          ###   ########.fr       */
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
** Structure de données des stacks
*/

typedef struct s_stack
{
	struct s_elem	*head;
	struct s_elem	*last;
	int				size;
	long long int	mediane;
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

/* parsing */
int				check_error(t_datas *datas);
int				case_arg_str(t_datas *datas);
int				case_arg_list(t_datas *datas);
int				count_elem(char **nbs);
int				error_case(t_datas *datas, unsigned int error_code);
long long int	*atoi_args(t_datas *datas, char **nbs);
/* sorting */
int				push_swap(t_datas *datas);
/* utils */
void			delete_node(struct s_elem **head_re);
void			clear_list(t_stack *stack);
/* operations */
int				ft_pa(t_datas *datas);
int				ft_pb(t_datas *datas);
int				ft_sa(t_datas *datas, int ss);
int				ft_sb(t_datas *datas, int ss);
int				ft_ss(t_datas *datas);
int				ft_ra(t_datas *datas, int rr);
int				ft_rb(t_datas *datas, int rr);
int				ft_rr(t_datas *datas);
int				ft_rra(t_datas *datas, int rrr);
int    			ft_rrb(t_datas *datas, int rrr);
int				ft_rrr(t_datas *datas);
int				append(struct s_elem **head_ref,
					struct s_elem **last_ref, long long int new_data);
int				push(struct s_elem **head_ref, long long int new_data);

#endif