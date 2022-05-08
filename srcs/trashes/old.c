#include "../includes/push_swap.h"

/*
    Push all nb < to the median in the stack b
*/
int    push_up_to_median(t_datas *datas)
{
    int i = 0;
    while (i < (datas->nb_elem / 2 - 3) && (datas->a.head != NULL && datas->a.head->next != NULL))
    {
        //get_median(&datas->a);
        if (datas->a.head->nb < datas->median) //recalculer la mediane a chaque cycle?
        {
            ft_pb(datas);
            i++;
        }
        else
        {
            if (datas->b.head != NULL && datas->b.head->next != NULL && datas->b.head->nb < datas->b.last->nb)
            {
                    ft_rr(datas);
            }
            else
                ft_ra(datas, 1);
        }
    }
    // printf("head a : %lld\n", datas->a.head->nb);
    // printf("last a : %lld\n", datas->a.last->nb);
    // printf("head b : %lld\n", datas->b.head->nb);
    // printf("last b : %lld\n", datas->b.last->nb);
    return (0);
}

int	test_operations(t_datas *datas)
{
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	ft_pb(datas);
	printstack(datas);
	ft_pa(datas);
	printstack(datas);
	ft_sa(datas, 1);
	printstack(datas);
	ft_sa(datas, 1);
	printstack(datas);
	ft_sb(datas, 1);
	printstack(datas);
	ft_ss(datas);
	printstack(datas);
	ft_ra(datas, 1);
	printstack(datas);
	ft_ra(datas, 1);
	printstack(datas);
	ft_rb(datas, 1);
	printstack(datas);
	ft_rr(datas);
	printstack(datas);
	ft_rra(datas, 1);
	printstack(datas);
	ft_rra(datas, 1);
	printstack(datas);
	ft_rrb(datas, 1);
	printstack(datas);
	ft_rrr(datas);
	printstack(datas);
	return (0);
}