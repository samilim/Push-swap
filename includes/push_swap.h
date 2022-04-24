/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/04/24 05:55:36 by salimon          ###   ########.fr       */
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
	long long int	min;
	long long int	max;
	long long int	median;
	int				move_count;
}				t_datas;

/* parsing */
void				check_error(t_datas *datas);
void	check_not_integer(t_datas *datas);
void	check_duplicates(t_datas *datas);
void				case_arg_str(t_datas *datas);
void				case_arg_list(t_datas *datas);
int				count_elem(char **nbs);
int				error_case(t_datas *datas, unsigned int error_code);
long long int	*atoi_args(t_datas *datas, char **nbs);
/* sorting */
void				push_swap(t_datas *datas);
/* utils */
void			delete_node(struct s_elem **head_re);
void			clear_list(t_stack *stack);
/* operations */
void				ft_pa(t_datas *datas);
void				ft_pb(t_datas *datas);
void				ft_sa(t_datas *datas, int ss);
void				ft_sb(t_datas *datas, int ss);
void				ft_ss(t_datas *datas);
void				ft_ra(t_datas *datas, int rr);
void				ft_rb(t_datas *datas, int rr);
void				ft_rr(t_datas *datas);
void				ft_rra(t_datas *datas, int rrr);
void    			ft_rrb(t_datas *datas, int rrr);
void				ft_rrr(t_datas *datas);
int				append(struct s_elem **head_ref,
					struct s_elem **last_ref, long long int new_data);
int				push(struct s_elem **head_ref, long long int new_data);

void printstack(t_datas	*datas);

#endif