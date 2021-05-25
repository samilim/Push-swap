/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:55:42 by salimon           #+#    #+#             */
/*   Updated: 2021/05/25 05:08:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_stack_a
{
    void			*content;
    struct s_stack_a	*next;

}					t_stack_a;

typedef struct		s_stack_b
{
	void			*content;
    struct s_stack_b	*next;
}					t_stack_b;


#endif