//
// Created by Aleksey Tverdokhleb on 10/25/17.
//

#include "../includes/ft_select.h"

void 	max_last_len(void)
{
	t_main *store;
	int start_poz;
	int index;
	t_arg_node *tmp;

	store = store_t_main_struct(NULL);
	index = store->total_nodes - 1;
	start_poz = (int)((store->max_len + store->shift) *
					  (index / store->li));
	tmp = store->tail;
	store->last_len = 0;
	while (start_poz == (int)((store->max_len + store->shift) *
							  (index / store->li)) && tmp)
	{
		if (ft_strlen(tmp->value) > store->last_len)
			store->last_len = ft_strlen(tmp->value);
		tmp = tmp->prew;
		index--;
	}
}

int count_col(int index)
{
	t_main *store;
	int col;

	store = store_t_main_struct(NULL);
	col = (int)((store->max_len + store->shift) *
				(index / store->li));
	return (col);
}

void	mov_elem(t_main *main_struct, int index)
{
	make_tgoto("cm", count_col(index),
			   (index % main_struct->li));
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
	mov_elem(store, store->index_cur);

	store->curr = (store->curr->next) ? store->curr->next : store->head;
	store->under = store->index_cur;
	print_selected(store->curr);
}

void	move_up(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	unset_mark();
	count_shift(-1);
	mov_elem(store, store->index_cur);

	store->curr = (store->curr->prew) ? store->curr->prew : store->tail;
	store->under = store->index_cur;
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
		mov_elem(store, store->index_cur);

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
		mov_elem(store, store->index_cur);

		store->curr = get_index(store->curr, index, store->index_cur);
		print_selected(store->curr);
	}
}

void	select_elem(void)
{
	t_main *store;

	store = store_t_main_struct(NULL);
	store->curr->select ^= 1;
	mov_elem(store, store->index_cur);
	if (store->curr->select)
		print_inverted(store->curr->value);
	else
		ft_putstr(store->curr->value);
}