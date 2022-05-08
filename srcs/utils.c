#include "../includes/push_swap.h"

void printstack(t_datas	*datas)
{
	t_elem *tmp;

	tmp = datas->a.head;
    printf("\na :\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        tmp = tmp->next;
    }
	// printf("\na in reverse direction \n");
	// while (datas->a.last != NULL) {
    //     printf("%lld ", datas->a.last->nb);
    //     datas->a.last = datas->a.last->prev;
	// }
	tmp = datas->b.head;
	printf("\nb :\n");
    while (tmp != NULL) {
        printf("%lld ", tmp->nb);
        //datas->b.last = tmp;
        tmp = tmp->next;
    }
	printf("\n\n\n");
}