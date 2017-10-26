//
// Created by Aleksey Tverdokhleb on 10/25/17.
//

#include "../includes/ft_select.h"

void	count_and_mov_elem(t_main *main_struct)
{
	make_tgoto("cm", (int)((main_struct->max_len + main_struct->shift) *
						   (main_struct->index_cur / main_struct->li)),
			   (main_struct->index_cur % main_struct->li));
}

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
	count_and_mov_elem(store);

	store->curr = (store->curr->next) ? store->curr->next : store->head;
	print_selected(store->curr);
}

void	move_up(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	unset_mark();
	count_shift(-1);
	count_and_mov_elem(store);

	store->curr = (store->curr->prew) ? store->curr->prew : store->tail;
	print_selected(store->curr);
}

void	move_left(void)
{
	t_main *store;
	int index;

	store = store_t_main_struct(NULL);
	if (store->index_cur >= store->li)
	{
		unset_mark();
		index = store->index_cur;
		count_shift(-(store->li));
		count_and_mov_elem(store);

		store->curr = get_index(store->curr, index, store->index_cur);
		print_selected(store->curr);
	}
}

void	move_right(void)
{
	t_main *store;
	int index;

	store = store_t_main_struct(NULL);
	if ((store->index_cur + store->li) < store->total_nodes)
	{
		unset_mark();
		index = store->index_cur;
		count_shift(store->li);
		count_and_mov_elem(store);

		store->curr = get_index(store->curr, index, store->index_cur);
		print_selected(store->curr);
	}
}

void	select_elem(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	store->curr->select ^= 1;
	count_and_mov_elem(store);
	if (store->curr->select)
		print_inverted(store->curr->value);
	else
		ft_putstr(store->curr->value);
}