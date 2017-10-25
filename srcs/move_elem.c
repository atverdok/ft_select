//
// Created by Aleksey Tverdokhleb on 10/25/17.
//

#include "../includes/ft_select.h"

void	count_shift(int shift_elem)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	if (!store->index_cur && shift_elem < 0)
		store->index_cur = store->total_nodes;
	store->index_cur = (store->index_cur + shift_elem) % store->total_nodes;
}

void	move_down(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	unset_mark();
	count_shift(1);
	make_tgoto("cm", (store->index_cur / store->li), (store->index_cur % store->li));

	store->curr = (store->curr->next) ? store->curr->next : store->head;
	print_selected(store->curr);
}

void	move_up(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	unset_mark();
	count_shift(-1);
	make_tgoto("cm", (store->index_cur / store->li), (store->index_cur % store->li));

	store->curr = (store->curr->prew) ? store->curr->prew : store->tail;
	print_selected(store->curr);
}

void	select_elem(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	store->curr->select ^= 1;
	make_tgoto("cm", (store->index_cur / store->li),
			   (store->index_cur % store->li));
	if (store->curr->select)
		print_inverted(store->curr->value);
	else
		ft_putstr(store->curr->value);
}